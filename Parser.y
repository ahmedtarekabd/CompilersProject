%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include "symbol_table.h"  // Include the symbol table header
    #include "quadruple.h"

    void yyerror(const char *s);
    int yylex(void);
    extern FILE *yyin;
    extern int yylineno; // Declared in the scanner
    extern char *yytext; // Declared in the scanner
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
%type <symbolTableEntry> LOGICAL_EXP REL_EXP BLOCK // FOR_LOOP
%type <symbolTableEntry> EXP TERM FACTOR POWER//FUNCTION_STMTS
%type <symbolTableEntry> STMT STMTS ASSIGNMENT DECLARATION CONST_DECLARATION
%type <symbolTableEntry> IF_STMT
// %type <i> MATCHED_IF UNMATCHED_IF 
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
// MATCHED_IF                    
//     | UNMATCHED_IF  
//     | 
    // SWITCH_CASE 
    // | WHILE_LOOP        
    // | REPEAT_UNTIL_LOOP   
    // | FUNCTION_DECL SEMICOLON
    // | FUNCTION_DECL FUNCTION_BODY
    // | 
    BLOCK
    // | FOR_LOOP    
    | DECLARATION 
    | CONST_DECLARATION 
    | ASSIGNMENT           
    | LOGICAL_EXP SEMICOLON         //{ printf("logical %d\n", $1); }
    | IF_STMT
    ;

DECLARATION: PARAM_TYPE SEMICOLON {
                if (lookupSymbol($2) && isSymbolDeclaredInCurrentScope($2)) {
                    yyerror("Variable already declared in this scope");
                } else {
                    addSymbol($2, $1, false);  // Add variable to current scope
                }
            }
            // TODO: Add support for declarations with initial values
            ;

CONST_DECLARATION: CONST PARAM_TYPE ID SEMICOLON {
                if (lookupSymbol($3) && isSymbolDeclaredInCurrentScope($3)) {
                    yyerror("Variable already declared in this scope");
                } else {
                    addSymbol($3, $2, true);  // Add variable to current scope
                }
            }
            // TODO: Add support for constant declarations with initial values
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

// SWITCH_CASE: SWITCH LPAREN ID RPAREN LBRACE CASES CASE_DEFAULT RBRACE
//     {
//         printf("Switch case\n");
//         printf("Switch value: %f\n", $3);
//         // switch ($3) {
//         //     $6;
//         //     default:
//         //         $9;
//         //         break;
//         // }
//     }
// ;
// CASE_DEFAULT: DEFAULT COLON STMTS BREAK SEMICOLON
//     {
//         printf("Default case\n");
//         // default:
//         //     $4;
//         //     break;
//     }
//     | 
//     ;
// CASES: CASES CASE_BLOCK
//      | CASE_BLOCK
// ;

// CASE_BLOCK: CASE INTEGER COLON CASE_STMTS BREAK SEMICOLON
//     {
//         printf("Case %d\n", $2);
//         // case $2:
//         //     $4;
//         //     break;
//     }

// ;
// CASE_STMTS: STMTS
//           | 
//           ;


/* FOR_LOOP:
    FOR LPAREN ASSIGNMENT SEMICOLON LOGICAL_EXP SEMICOLON ASSIGNMENT RPAREN 
        {
            // Start a new scope for the loop
            enterScope();

            // Generate the label for the condition check
            char *conditionLabel = newLabel();
            printf("%s:\n", conditionLabel);

            // Generate the logical expression (condition) quadruple
            SymbolTableEntry *condition = $5; // Assuming LOGICAL_EXP returns a SymbolTableEntry*

            // Generate the label to exit the loop
            char *exitLabel = newLabel();

            // Add a quadruple to check the condition and branch to the exit label if false
            addQuadruple("IF_FALSE", condition, NULL, exitLabel);
        }
        STMTS 
        {
            // Generate the increment statement quadruple (for the third part of the for loop)
            addQuadruple($7->operat, $7->operand1, $7->operand2);

            // Jump back to the condition check
            addQuadruple("GOTO", NULL, NULL, conditionLabel);

            // Print the exit label
            char *exitLabel = newLabel();
            printf("%s:\n", exitLabel);

            // Exit the scope of the loop
            exitScope();
        }
    ; */



// WHILE_LOOP: WHILE LPAREN LOGICAL_EXP RPAREN LBRACE STMTS RBRACE
//     {
//         while ($3) {
//             printf("While loop\n");
//             $6;  
//         }
//     }

// ;
// REPEAT_UNTIL_LOOP: REPEAT LBRACE STMTS RBRACE UNTIL LPAREN LOGICAL_EXP RPAREN SEMICOLON
//     {
//         do {
//             printf("Repeat until loop\n");
//             $3;  
//         } while (!$7);
//     }
// ;

// MATCHED_IF: 
//     IF LPAREN LOGICAL_EXP RPAREN LBRACE MATCHED_IF RBRACE ELSE LBRACE MATCHED_IF RBRACE
//     {

//         printf("matched 1");
//         if ($3) {
//             $$ = $6;  // Execute the first `if` branch
//         } else {
//             $$ = $10;  // Execute the second `else` branch
//         }
//     }
//   | IF LPAREN LOGICAL_EXP RPAREN LBRACE STMT RBRACE ELSE LBRACE STMT RBRACE
//     {
//         printf("matched 2");
//         if ($3) { 
//             $$ = $6;  // Execute the `if` branch
//         } else {
//             $$ = $10;  // Execute the `else` branch
//         }
//     }
// ;


// UNMATCHED_IF:
//     IF LPAREN LOGICAL_EXP RPAREN LBRACE STMT RBRACE
//     {
//         printf("unmatched 1 %d\n", $3);
//         if ($3 != 0) {
//             $$ = $6;  // Execute the `if` branch
//             printf("If statement executed\n");
//         }
//     }
//   | IF LPAREN LOGICAL_EXP RPAREN LBRACE {enterScope()} 
//     MATCHED_IF RBRACE {exitScope()}
//     ELSE LBRACE {enterScope()}
//     UNMATCHED_IF RBRACE {exitScope()}
//     {
//         printf("unmatched 2");
//         if ($3) {
//             $$ = $6;  // Execute the nested `if`
//         }
//         else
//         {
//             $$ = $10;
//         }
//     }
// ;

IF_STMT : IF LPAREN LOGICAL_EXP RPAREN LBRACE STMTS RBRACE
    {
        printf("\n\nNo else If statement: logic_exp: %s - stmt: %s\n\n", ($3)->name, ($6->name));
        if ($3) {
            $$ = $6;  // Execute the `if` block
        }
    }
    | IF LPAREN LOGICAL_EXP RPAREN LBRACE STMTS RBRACE ELSE LBRACE STMTS RBRACE
    {
        printf("\n\nIf statement: logic_exp: %s - if: %s - else: %s\n\n", ($3)->name, $6->name, $10->name);
        if ($3) {
            $$ = $6;  // Execute the `if` block
        } else {
            $$ = $10;  // Execute the `else` block
        }
    }
    ;

ASSIGNMENT : ID ASSIGN LOGICAL_EXP SEMICOLON
    { 
        // Assign the value of EXP to the variable ID
        // assign_var($1, $3); 
        SymbolTableEntry *entry = lookupSymbol($1);
        if (!entry) {
            yyerror("Variable not declared in any scope");
        } else {
            printf("Assignment statement: %s = %s\n", $1, ($3)->name);
            SymbolTableEntry *temp = addQuadruple("ASSIGN", entry, $3);
            updateSymbolValue($1, ($3)->value);
            entry->isInitialized = 1;  // Mark the variable as initialized
        }
        $$ = $3;
    }            
;

/* ! LOGICAL_EXP : LOGICAL_EXP OR REL_EXP (Left recursion/associativity) */
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
            printf("Variable '%s' used.\n", $1);
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

/* void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
} */
void yyerror(const char *s) {
    fprintf(stderr, "%s at line %d, near '%s'\n", s, yylineno, yytext);
}


int main(int argc, char **argv) {
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
