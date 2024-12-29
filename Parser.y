%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include "symbol_table.h" 
    #include "quadruple.h"
    #include "utils/label_stack.h" 

    void yyerror(const char *s);
    int yylex(void);
    extern FILE *yyin;
    LabelStack *labelStack;
    char *currentSwitchVar;
    char* nextLabel;
    char* endLabel; 

%}

%union {
    int i;
    char c;
    float f;
    char *s;  
    char *Dtype;
    SymbolTableEntry *symbolTableEntry;
}

%token POW NOT OR AND EQ NE LT LE GT GE ASSIGN LPAREN RPAREN LBRACE RBRACE SEMICOLON COLON
%token FOR WHILE REPEAT UNTIL
%token IF ELSE SWITCH CASE BREAK DEFAULT
%token SUB ADD DIV MUL
%token INT_TYPE FLOAT_TYPE CHAR_TYPE VOID_TYPE CONST
%token RETURN COMMA 
%token ERROR


%token <s> INTEGER
%token <s> FLOAT
%token <s> CHAR
%token <s> ID

// %type <i> EXP TERM FACTOR REL_EXP LOGICAL_EXP STMT ASSIGNMENT STMTS 
%type <symbolTableEntry> LOGICAL_EXP REL_EXP BLOCK FOR_LOOP WHILE_LOOP REPEAT_UNTIL_LOOP MATCHED_IF UNMATCHED_IF 
%type <symbolTableEntry> EXP TERM FACTOR POWER //FUNCTION_STMTS
%type <symbolTableEntry> STMT STMTS ASSIGNMENT DECLARATION CONST_DECLARATION ASSIGNMENT_FORLOOP //IF_STMT
// %type <symbolTableEntry> FOR_LOOP WHILE_LOOP REPEAT_UNTIL_LOOP SWITCH_CASE CASES CASE_BLOCK
// %type <i> FUNCTION_DECL FUNCTION_BODY  PARAMS PARAM
%type <Dtype> PARAM_TYPE //RETURN_TYPE



%%

/* Production rules */

STMTS : STMTS STMT  { /* Handle multiple statements */ }
      | STMT        { /* Handle a single statement */ }
      | ERROR       { fprintf(stderr, "Syntax error: Skipping invalid statement.\n"); yyerrok; }
      ;
      
BLOCK : LBRACE {
           enterScope();  // Enter a new scope
       }
       STMTS RBRACE {
           exitScope();   // Exit the current scope
       }
       {
           printf("Block parsed\n");
       }

       ;


STMT: 
     MATCHED_IF                    
    | UNMATCHED_IF  
//     |   
    // | FUNCTION_DECL SEMICOLON
    // | FUNCTION_DECL FUNCTION_BODY
   
    | SWITCH_BLOCK
    | BLOCK
    | FOR_LOOP    
    | WHILE_LOOP
    | REPEAT_UNTIL_LOOP
    | DECLARATION 
    | CONST_DECLARATION 
    | ASSIGNMENT           
    | LOGICAL_EXP SEMICOLON         
    ;

DECLARATION: PARAM_TYPE ID SEMICOLON {
                if (lookupSymbol($2) && isSymbolDeclaredInCurrentScope($2)) {
                    yyerror("Variable already declared in this scope");
                } else {
                    addSymbol($2, $1, false);  // Add variable to current scope
                }
            }
            ;

CONST_DECLARATION: CONST PARAM_TYPE ID SEMICOLON {
                if (lookupSymbol($3) && isSymbolDeclaredInCurrentScope($3)) {
                    yyerror("Variable already declared in this scope");
                } else {
                    addSymbol($3, $2, true);  // Add variable to current scope
                }
            }
            ;

// FUNCTION_DECL: DECLARATION LPAREN PARAMS RPAREN
//     {
//         printf("Function declaration\n");
//         // Declare a function with the given return type, name, and parameters
//         // declare_function($1, $2, $4);
//     }
// ;

// FUNCTION_BODY: LBRACE FUNCTION_STMTS RBRACE
//     {
//         printf("Function body parsed\n");
//     }
//     ;

// FUNCTION_STMTS: STMTS RETURN EXP SEMICOLON  
//               | RETURN EXP SEMICOLON
//               | RETURN SEMICOLON
//               ;


// PARAMS: PARAMS COMMA PARAM
//       | PARAM
//       | { $$ = 0; }
//       ;

// PARAM : PARAM_TYPE ID {
//             printf("Parameter %s of type %s\n", $2, $1);
//             if (lookupSymbol($2)) {
//                 yyerror("Variable already declared in this scope");
//             } else {
//                 printf("Parameter %s of type %s\n", $2, $1);
//                 addSymbol($2, $1);  // Add variable to current scope
//             }
//             // $$ = $2;
//         }
//         ;


PARAM_TYPE: INT_TYPE        { $$ = "int"; }
          | FLOAT_TYPE      { $$ = "float"; }
          | CHAR_TYPE       { $$ = "char"; }
          ;

// RETURN_TYPE: VOID_TYPE      
//            | PARAM_TYPE     
//            ;

SWITCH_BLOCK: SWITCH LPAREN ID RPAREN 
            LBRACE { 
                enterScope(); 
                currentSwitchVar = $3;
                addSymbol($3, "int", false);
                endLabel = newLabel();
            }
            SWITCH_CASE RBRACE
            {
                exitScope();
                currentSwitchVar = NULL;
                endLabel = NULL;

            }
            ;

SWITCH_CASE: CASE_STMTS
            | CASE_STMTS DEFAULT_STMT
            | DEFAULT_STMT
            ;

CASE_STMTS: CASE_STMT
          | CASE_STMTS CASE_STMT  
          ;

CASE_STMT: CASE INTEGER COLON 
    {
    // if i!=1 goto label2
        SymbolTableEntry *switchVar = lookupSymbol(currentSwitchVar);
        SymbolTableEntry *caseVar = addSymbol($2, "int", false);
        SymbolTableEntry *condition = addQuadruple("EQ", switchVar, caseVar);
        nextLabel = newLabel();
        switchcaseQuadruple(condition , nextLabel ,endLabel, true,false);

    }
    STMTS 
    {
     // goto endLabel
     // label2;
        switchcaseQuadruple(NULL , nextLabel ,endLabel, false,false); 
    }
    BREAK SEMICOLON
    ;
    
DEFAULT_STMT: DEFAULT COLON 
    STMTS BREAK SEMICOLON
    {
        switchcaseQuadruple(NULL , endLabel ,endLabel, false,false); 
    }
    ;
/*
//switch case
switch (i) {
    case 1:
        some code
        break;
    case 2:
        some code
        break;
    default:
        some code
        break;
}
---->
if i==1 goto label1
if i==2 goto label2
goto label3
label1:
if i!=1 goto label2
some code
goto label4
label2:
if i!=2 goto label3
some code
goto label4
label3:
some code
label4:
*/




/*
for loop
if  i>=6 goto label2
label1: 
some code
if (i<6) goto label1
label2:
*/
FOR_LOOP: FOR LPAREN ASSIGNMENT_FORLOOP SEMICOLON LOGICAL_EXP SEMICOLON ASSIGNMENT_FORLOOP RPAREN 
    LBRACE
        {
            // Start a new scope for the loop
            enterScope();
            SymbolTableEntry *condition = $5; // Assuming LOGICAL_EXP returns a SymbolTableEntry*
            Labels *labels = (Labels *)malloc(sizeof(Labels));
            labels->loopLabel = newLabel();
            labels->exitLabel = newLabel();
            addQuadrupleLabel(condition, labels->loopLabel, labels->exitLabel, true);
            pushLabelStack(&labelStack, labels);  // Push labels onto the stack
        }
        STMTS 
        RBRACE
        {   
            Labels *labels = popLabelStack(labelStack);  // Pop labels from the stack
           
            addQuadrupleLabel(NULL, labels->loopLabel, labels->exitLabel, false);
            free(labels);
            exitScope();
        }
    ;

/*
while (i<6) {
    some code
}
---->
label1:
if i>=6 goto label2
some code
goto label1
label2:
*/

WHILE_LOOP: WHILE LPAREN LOGICAL_EXP RPAREN LBRACE
   {
            // Start a new scope for the loop
            enterScope();
            SymbolTableEntry *condition = $3; // Assuming LOGICAL_EXP returns a SymbolTableEntry*
            Labels *labels = (Labels *)malloc(sizeof(Labels));
            labels->loopLabel = newLabel();
            labels->exitLabel = newLabel();
            addQuadrupleLabel(condition, labels->loopLabel, labels->exitLabel, true);
            pushLabelStack(&labelStack, labels);  // Push labels onto the stack
        }
 STMTS RBRACE
     {   
            Labels *labels = popLabelStack(labelStack);  // Pop labels from the stack
           
            addQuadrupleLabel(NULL, labels->loopLabel, labels->exitLabel, false);
            free(labels);
            exitScope();
        }
;
/* 
repeat {
    some code
} until (i<6)
---->
label1:
some code
if i<6 goto label1

*/
REPEAT_UNTIL_LOOP: REPEAT LBRACE 
{
    enterScope();
    Labels *labels = (Labels *)malloc(sizeof(Labels));
    labels->loopLabel = newLabel();
    
    pushLabelStack(&labelStack, labels);  // Push labels onto the stack
    addQuadrupleLabel(NULL, labels->loopLabel, NULL, true);

}
STMTS RBRACE
 UNTIL LPAREN LOGICAL_EXP 
 {
    SymbolTableEntry *condition = $8;
    Labels *labels = popLabelStack(labelStack);  // Pop labels from the stack
    addQuadrupleLabel(condition, labels->loopLabel, NULL, false);
    free(labels);
    exitScope();

}
 RPAREN SEMICOLON
    
;
/*
if (i>=6) {
    some code
} else {
    some code
} 
---->
if i>=6 goto label1
some code
goto label2
label1:
some code
label2:
*/
// MATCHED_IF: 
//     IF LPAREN LOGICAL_EXP RPAREN LBRACE MATCHED_IF RBRACE ELSE LBRACE MATCHED_IF RBRACE
//     {

      
//     }
//   | STMTS
//     {
       
//     }
// ;

/*
if (i>=6) {
    some code1
}
else {
    some code2
}
---->

if i>=6 goto label1
some code2
goto label2
label1:
some code1
label2:
*/

MATCHED_IF : 
UNMATCHED_IF
ELSE LBRACE
    {
        enterScope();
        //go to end
        Labels *labels = (Labels *)malloc(sizeof(Labels));
        labels->exitLabel = newLabel();
        matchedIfQuadruple( labels->exitLabel, true);
        pushLabelStack(&labelStack, labels);  
    }
    STMTS RBRACE   //stmts is somecode2
    {
        Labels *labels = popLabelStack(labelStack);  
        matchedIfQuadruple( labels->exitLabel, false);
        free(labels);
        exitScope();
    }
    ; 
/*
unmatched if  
if (i>=6) {
    some code
}
---->
if i>=6 goto label1
goto label2
label1:
some code
label2:
*/
/*
if i>=6 goto label1
some code2
goto label2
label1:
some code1
label2:
*/
UNMATCHED_IF:
    IF LPAREN LOGICAL_EXP RPAREN LBRACE
    {
        // Start a new scope for the if block
        enterScope();
        SymbolTableEntry *condition = $3; // Assuming LOGICAL_EXP returns a SymbolTableEntry*
        Labels *labels = (Labels *)malloc(sizeof(Labels));
        labels->loopLabel = newLabel();
        labels->exitLabel = newLabel();
        unmatchedIfQuadruple(condition, labels->loopLabel, labels->exitLabel, true);
        pushLabelStack(&labelStack, labels);  // Push labels onto the stack

    } STMTS RBRACE
    {
        Labels *labels = popLabelStack(labelStack);  // Pop labels from the stack
        unmatchedIfQuadruple(NULL, labels->loopLabel, labels->exitLabel, false);
        free(labels);
        exitScope();
    }    
; 
ASSIGNMENT : ID ASSIGN LOGICAL_EXP SEMICOLON
    { 
        
        SymbolTableEntry *entry = lookupSymbol($1);
        if (!entry) {
            yyerror("Variable not declared in any scope");
        } else {
            SymbolTableEntry *temp = addQuadruple("ASSIGN", entry, $3);
            updateSymbolValue($1, ($3)->value);
            entry->isInitialized = 1;  
        }
        $$ = $3;
    }            
;

ASSIGNMENT_FORLOOP : ID ASSIGN LOGICAL_EXP 
    { 
        // Assign the value of EXP to the variable ID
        // assign_var($1, $3); 
        SymbolTableEntry *entry = lookupSymbol($1);
        if (!entry) {
            yyerror("Variable not declared in any scope");
        } else {
            SymbolTableEntry *temp = addQuadruple("ASSIGN", entry, $3);
            updateSymbolValue($1, ($3)->value);
            entry->isInitialized = 1;  // Mark the variable as initialized
        }
        $$ = $3;
    }            
;



LOGICAL_EXP : REL_EXP OR LOGICAL_EXP   { $$ = addQuadruple("OR", $1, $3); }
            | REL_EXP AND LOGICAL_EXP  { $$ = addQuadruple("AND", $1, $3); }
            | REL_EXP                  { $$ = $1;  }
            ;

REL_EXP : EXP EQ EXP         { $$ = addQuadruple("EQ", $1, $3); }
        | EXP NE EXP         { $$ = addQuadruple("NE", $1, $3); }
        | EXP LT EXP         { $$ = addQuadruple("LT", $1, $3); }
        | EXP LE EXP         { $$ = addQuadruple("LE", $1, $3); }
        | EXP GT EXP         { $$ = addQuadruple("GT", $1, $3); }
        | EXP GE EXP         { $$ = addQuadruple("GE", $1, $3); }
        | EXP                { $$ = $1; }
        ;

EXP : EXP ADD TERM           
    {
        $$ = addQuadruple("ADD", $1, $3);
        printf("Adding %s and %s\n", ($1)->name, ($3)->name);
    }
    | EXP SUB TERM
    {
        $$ = addQuadruple("SUB", $1, $3);
        printf("Subtracting %s from %s\n", ($3)->name, ($1)->name);
    }
    | TERM                   { $$ = $1; }
    ;

TERM : TERM MUL POWER   { $$ = addQuadruple("MUL", $1, $3); }
     | TERM DIV POWER       
     { 
         if (strcmp(($3)->name, "0") == 0) { 
            yyerror("Division by zero"); 
            exit(1); 
         } else {
            $$ = addQuadruple("DIV", $1, $3);
            printf("Dividing %s by %s\n", ($1)->name, ($3)->name);
         }
     }
      
     | POWER                { $$ = $1; }
     ;

POWER : FACTOR POW POWER    { $$ = addQuadruple("POW", $1, $3); }
      | FACTOR              { $$ = $1; }
      ;

FACTOR : LPAREN LOGICAL_EXP RPAREN 
        { 
            $$ = $2; 
            printf("Logical expression evaluated.\n"); 
        }
       | SUB FACTOR          
        { 
            $$ = addQuadruple("NEG", $2, NULL);
            printf("Negation applied: %f\n", $$); 
        }
       | NOT FACTOR          
        { 
            $$ = addQuadruple("NOT", $2, NULL);
            printf("Logical NOT applied: %d\n", $$); 
        }
       | INTEGER             
        { 
            $$ = addSymbol($1, "int", false);
            printf("Integer constant: %s\n", $1); 
        }
       | FLOAT               
        { 
            $$ = addSymbol($1, "float", false);
            printf("Float constant: %s\n", $1);
        }
       | CHAR                
        { 
            $$ = addSymbol($1, "char", false);
            printf("Character constant: %s\n", $1);
        }
       | ID                  
        { 
            // Look up the variable in the symbol table
            SymbolTableEntry *entry = lookupSymbol($1);
            if (!entry) {
                yyerror("Variable not declared in any scope");
            } else {
                if (!entry->isInitialized) {
                    yyerror("Variable used before initialization");
                }
                entry->isUsed = 1;  // Mark the variable as used
                $$ = lookupSymbol($1);  // Retrieve its runtime value
                printf("Variable '%s' of type '%s' used. Value: %f\n", $1, entry->type, $$);
            }
        }
       ;


%% 

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(int argc, char **argv) {

     // Clear the contents of quadruples.txt
    FILE *quadFile = fopen("quadruples.txt", "w");
    if (quadFile == NULL) {
        fprintf(stderr, "Error opening quadruples.txt for writing!\n");
        return 1;
    }
    fclose(quadFile);
    
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror(argv[1]);
            return 1;
        }
    } 
  
    if (yyparse() == 0) {
        printf("Parsing successful\n");
        printQuadruples();
    } else {
        printf("Parsing failed\n");
    }
    return 0;
}
