%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include "symbol_table.h" 
    #include "quadruple.h"
    #include "utils/label_stack.h" 
    #include "utils/for_loop_stack.h"
    void yyerror(const char *s);
    // void semanticError(const char *s) ;
    int yylex(void);
    void clearFile(const char *filename) ;
    extern FILE *yyin;
    extern int yylineno;  
    LabelStack *labelStack;
    ForLoopStack *forLoopStack;
    
    char *currentSwitchVar;
    char* nextLabel;
    char* endLabel; 
    FunctionDef *currentFunction;
    //create array of function definitions 
    FunctionDef *functionDefinitions[200];
    int functionsCount = 0;
    SymbolTableEntry * currentFunctionParams[100];
    int currentFunctionParamsCount = 0;
    void initializeCurrentFunction(const char *name, const char *returnType) {
    if (currentFunction) {
        currentFunction = NULL;
    }
    currentFunction = (FunctionDef *)malloc(sizeof(FunctionDef));
    currentFunction->name = strdup(name);
    currentFunction->returnType = strdup(returnType);
    currentFunction->paramNames = NULL;
    currentFunction->paramTypes = NULL;
    currentFunction->paramCount = 0;
}
%}
%union {
    int i;
    char c;
    float f;
    char *s;  
    char *Dtype;
    SymbolTableEntry *symbolTableEntry;
}

%token POW NOT OR AND EQ NE LT LE GT GE ASSIGN LPAREN RPAREN LBRACE RBRACE SEMICOLON COLON MOD
%token FOR WHILE REPEAT UNTIL
%token IF ELSE SWITCH CASE BREAK DEFAULT
%token SUB ADD DIV MUL
%token INT_TYPE FLOAT_TYPE CHAR_TYPE VOID_TYPE CONST STRING_TYPE
%token RETURN COMMA 
%token ERROR


%token <s> INTEGER
%token <s> FLOAT
%token <s> CHAR
%token <s> ID
%token <s> STRING

// %type <i> EXP TERM FACTOR REL_EXP FINAL_EXP STMT ASSIGNMENT STMTS 
%type <symbolTableEntry> FINAL_EXP REL_EXP BLOCK FOR_LOOP ASSIGNMENT_FOR_LOOP_END WHILE_LOOP REPEAT_UNTIL_LOOP MATCHED_IF UNMATCHED_IF LOGICAL_EXP
%type <symbolTableEntry> EXP TERM FACTOR POWER //FUNCTION_STMTS
%type <symbolTableEntry> STMT STMTS ASSIGNMENT DECLARATION CONST_DECLARATION ASSIGNMENT_FORLOOP 
%type <symbolTableEntry> FUNCTION_DEFINITION   PARAMS PARAM FUNCTION_BODY FUNCTION_PARAMS FUNCTION_PARAM FUNCTION_START VOID_FUNCTION_BODY FUNCTION_CALL
// %type <symbolTableEntry> FOR_LOOP WHILE_LOOP REPEAT_UNTIL_LOOP SWITCH_CASE CASES CASE_BLOCK
// %type <i> FUNCTION_DECL FUNCTION_BODY 
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
    | SWITCH_BLOCK
    | BLOCK
    | FOR_LOOP    
    | WHILE_LOOP
    | REPEAT_UNTIL_LOOP
    | DECLARATION 
    | CONST_DECLARATION 
    | ASSIGNMENT           
    | FINAL_EXP SEMICOLON
    | FUNCTION_DEFINITION
    | RETURN SEMICOLON             
    {
        if (currentFunction) {
            if (strcmp("void", currentFunction->returnType) != 0) {
                semanticError("Function must return a value");
            }
        }
    }
    | RETURN FINAL_EXP SEMICOLON    
    {
        
        if (currentFunction) {
            if(strcmp("void", currentFunction->returnType) == 0){
                semanticError("Function return type is void");
            }
            else if (strcmp(($2)->type, currentFunction->returnType) != 0) {
                semanticError("Function return type does not match");
            }
        }
    }
    ;
DECLARATION: PARAM_TYPE ID SEMICOLON {
                if (lookupSymbol($2) && isSymbolDeclaredInCurrentScope($2)) {
                    semanticError("Variable already declared in this scope");
                } else {
                    $$ = addSymbol($2, $1, false,false);  // Add variable to current scope
                }
            }
            ;

CONST_DECLARATION: CONST PARAM_TYPE ID SEMICOLON {
                if (lookupSymbol($3) && isSymbolDeclaredInCurrentScope($3)) {
                    semanticError("Variable already declared in this scope");
                } else {
                    addSymbol($3, $2, true,false);  // Add variable to current scope
                }
            }
            ;
FUNCTION_DEFINITION: FUNCTION_START 
    LPAREN FUNCTION_PARAMS RPAREN FUNCTION_BODY
    {
        printf("Function definition\n");

    }
    |
    VOID_TYPE ID
    {
        if (currentFunction)
        {
            yyerror("Cannot declare a function inside another function");
            exit(1);
        }
        if (lookupSymbol($2) && isSymbolDeclaredInCurrentScope($2)) {
            semanticError("Function already declared in this scope");
        } else {
            addSymbol($2, "void", false,true);  // Add function to current scope 
            initializeCurrentFunction($2, "void");
        }
    }
    LPAREN FUNCTION_PARAMS RPAREN VOID_FUNCTION_BODY 
    
    ; 
    FUNCTION_BODY:
    LBRACE  { 
          enterScope();
            for (int i = 0; i < currentFunction->paramCount; i++) {
                SymbolTableEntry * s= addSymbol(currentFunction->paramNames[i], currentFunction->paramTypes[i], false,false);
                s->isInitialized = 1;
            }
            addQuadrupleFunction(currentFunction,true);
        
         }
    STMTS
    // RETURN 
    // FINAL_EXP SEMICOLON   
    RBRACE  {
        // currentFunction->returnVar = ($5)->name;
        addQuadrupleFunction(currentFunction,false);
        printf("function name: %s\n", currentFunction->name);
        functionDefinitions[functionsCount] = currentFunction;
        printf("functionDefinitions[functionsCount]->name: %s\n", functionDefinitions[functionsCount]->name);
        functionsCount++;
        // freeCurrentFunction();
        currentFunction = NULL;
        exitScope();
        }
    ;

VOID_FUNCTION_BODY:
    LBRACE  { 
          enterScope();
            for (int i = 0; i < currentFunction->paramCount; i++) {
                addSymbol(currentFunction->paramNames[i], currentFunction->paramTypes[i], false,false);
            }
        addQuadrupleFunction(currentFunction,true);
         }
    STMTS 
    // RETURN SEMICOLON   
    RBRACE  {
        addQuadrupleFunction(currentFunction,false);
        functionDefinitions[functionsCount] = currentFunction;
        functionsCount++;
        // freeCurrentFunction();
        currentFunction = NULL;
        exitScope();
        }
    ;
    
FUNCTION_PARAMS: FUNCTION_PARAMS COMMA FUNCTION_PARAM
    | FUNCTION_PARAM
    ;

    
FUNCTION_PARAM: PARAM_TYPE ID {
    
    currentFunction->paramCount++;
    currentFunction->paramNames = (char **)realloc(currentFunction->paramNames, currentFunction->paramCount * sizeof(char *));
    currentFunction->paramTypes = (char **)realloc(currentFunction->paramTypes, currentFunction->paramCount * sizeof(char *));
    currentFunction->paramNames[currentFunction->paramCount - 1] = strdup($2);
    currentFunction->paramTypes[currentFunction->paramCount - 1] = strdup($1); 
    //TODO : ADD PARAMETERS TO SYMBOL TABLE IN THE FUNCTION SCOPE 
    printf("Parameter %s of type %s\n", $2, $1);
        }
        |
        ;

PARAMS: PARAMS COMMA PARAM
      | PARAM
      ;
PARAM : PARAM_TYPE ID {
            printf("Parameter %s of type %s\n", $2, $1);
            SymbolTableEntry *entry = lookupSymbol($2);
            if (entry) {
                semanticError("Variable already declared in this scope");
            } else {
                printf("Parameter %s of type %s\n", $2, $1);
                $$ = addSymbol($2, $1, false,false);  // Add variable to current scope
            }
            $$ = entry;
            
        }
        ;
PARAM_TYPE: INT_TYPE        { $$ = "int"; }
          | FLOAT_TYPE      { $$ = "float"; }
          | CHAR_TYPE       { $$ = "char"; }
          | STRING_TYPE     { $$ = "string"; }
          ;
FUNCTION_START: PARAM_TYPE ID {
    if (currentFunction)
    {
        yyerror("Cannot declare a function inside another function");
        exit(1);
    }
    if (lookupSymbol($2) && isSymbolDeclaredInCurrentScope($2)) {
        semanticError("Function already declared in this scope");
    } else {
        addSymbol($2, $1, false,true);  // Add function to current scope 
        initializeCurrentFunction($2, $1);
    }
}
FUNCTION_CALL:  ID LPAREN FUNCTION_CALL_PARAMS RPAREN 
    {
        SymbolTableEntry *entry = lookupSymbol($1);
        if (!entry) {
            semanticError("Function not declared in any scope");
        } else {
            printf("functionsCount: %d\n", functionsCount);
            // for loop on the functionDefinitions array to find the function with the same name 
            for (int i = 0; i < functionsCount; i++) {

                if (strcmp(functionDefinitions[i]->name, $1) == 0) {
                    if (functionDefinitions[i]->paramCount != currentFunctionParamsCount) {
                        semanticError("Function called with incorrect number of parameters");
                    } else {
                        for (int j = 0; j < currentFunctionParamsCount; j++) {
                            if (strcmp(functionDefinitions[i]->paramTypes[j], currentFunctionParams[j]->type) != 0) {
                                semanticError("Function called with incorrect parameter types");
                            }
                        }
                    }
                    entry->type = functionDefinitions[i]->returnType;

                }
            }
        }
        $$ = entry;
        printf("function %s , type %s\n", entry->name, entry->type);
        SymbolTableEntry * func = addQuadrupleFunctionCall(entry ,currentFunctionParams, currentFunctionParamsCount);
        func->type = entry->type;
        if(strcmp(func->type, "void") != 0){
            $$ = func;
        }
        currentFunctionParamsCount = 0;

    }
    ;
FUNCTION_CALL_PARAMS: FUNCTION_CALL_PARAMS COMMA FINAL_EXP
    {
        currentFunctionParams[currentFunctionParamsCount] = $3;
        currentFunctionParamsCount++;
    }

    | FINAL_EXP
    {
        currentFunctionParams[currentFunctionParamsCount] = $1;
        currentFunctionParamsCount++;

    }
    |
    ;
SWITCH_BLOCK: SWITCH LPAREN ID RPAREN 
            LBRACE { 
                enterScope(); 
                currentSwitchVar = $3;
                addSymbol($3, "int", false,false);
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
        SymbolTableEntry *caseVar = addSymbol($2, "int", false,false);
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
    |
    CASE CHAR COLON 
    {
    // if i!=1 goto label2
        SymbolTableEntry *switchVar = lookupSymbol(currentSwitchVar);
        SymbolTableEntry *caseVar = addSymbol($2, "int", false,false);
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
FOR_LOOP: FOR LPAREN ASSIGNMENT_FORLOOP SEMICOLON 
{
    Labels *labels = (Labels *)malloc(sizeof(Labels));
    labels->loopLabel = newLabel();
    labels->exitLabel = newLabel();
    pushLabelStack(&labelStack, labels);  // Push labels onto the stack 
    addQuadrupleLabel(NULL, labels->loopLabel,NULL, true);

}
FINAL_EXP SEMICOLON
{
            // Start a new scope for the loop
            
            SymbolTableEntry *condition = $6; // Assuming FINAL_EXP returns a SymbolTableEntry*
          
            Labels *labels = popLabelStack(labelStack);  // Pop labels from the stack
            addQuadrupleLabel(condition, labels->loopLabel, labels->exitLabel, true);
            pushLabelStack(&labelStack, labels);  // Push labels onto the stack
            
            
        }
 ASSIGNMENT_FOR_LOOP_END RPAREN 
        LBRACE
        {
            enterScope();
        }
        STMTS 
        RBRACE
        {   
            Labels *labels = popLabelStack(labelStack);  // Pop labels from the stack
            ForLoopAttributes *forLoopAttributes = popForLoopStack(forLoopStack);
            SymbolTableEntry *operand1;
            SymbolTableEntry *operand2;
            operand1 = (SymbolTableEntry *)malloc(sizeof(SymbolTableEntry));
            operand2 = (SymbolTableEntry *)malloc(sizeof(SymbolTableEntry));

            operand1->name = forLoopAttributes->id;
            operand2->name = forLoopAttributes->final_expression_result;
            operand1->type = forLoopAttributes->id_type;
            operand2->type = forLoopAttributes-> final_expression_result_type;
            addQuadruple("ASSIGN", operand1, operand2);
            free(forLoopAttributes);
            addQuadrupleLabel(NULL, labels->loopLabel, labels->exitLabel, false);
            
            free(labels);
            exitScope();
        }
    ;
ASSIGNMENT_FOR_LOOP_END : ID ASSIGN FINAL_EXP 
    { 
        // Assign the value of EXP to the variable ID
        // assign_var($1, $3); 
        bool isVoid = strcmp(($3)->type, "void") == 0;
                if (isVoid) {
                    semanticError("void value cannot be assigned to a variable");
                }
        SymbolTableEntry *entry = lookupSymbol($1);
        if (!entry) {
            semanticError("Variable not declared in any scope");
        } else {
            if(entry->isTemp){
                semanticError("Cannot assign a value to a function.");
            }
            //check types before assigning
            if (strcmp(entry->type, ($3)->type) != 0) {
                semanticError("Type mismatch in assignment");
            }
            ForLoopAttributes *forLoopAttributes = (ForLoopAttributes *)malloc(sizeof(ForLoopAttributes));
            SymbolTableEntry *entry = lookupSymbol($1);
            if(!entry){ 
                char message[256]; // Adjust the size as needed
                sprintf(message, " Variable %s is not declared in the current scope",($1));
                semanticError(message);
                exit(1);
            }
            forLoopAttributes->id = entry->name;
            forLoopAttributes->id_type = entry->type;
            forLoopAttributes->final_expression_result= ($3)->name;
            forLoopAttributes->final_expression_result_type = ($3)->type;
            pushForLoopStack(&forLoopStack, forLoopAttributes);
           // $$ = addQuadruple("ASSIGN", entry, $3);
           // updateSymbolValue($1, ($3)->value);
            entry->isInitialized = 1;  // Mark the variable as initialized
        }
        $$ = $3;
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

WHILE_LOOP: WHILE LPAREN 
{
    Labels *labels = (Labels *)malloc(sizeof(Labels));
            labels->loopLabel = newLabel();
            labels->exitLabel = newLabel();
            pushLabelStack(&labelStack, labels);
            addQuadrupleLabel(NULL, labels->loopLabel,NULL, true);
}

FINAL_EXP RPAREN LBRACE
   {
            // Start a new scope for the loop
            enterScope();
            SymbolTableEntry *condition = $4; // Assuming FINAL_EXP returns a SymbolTableEntry*
            
            Labels *labels = popLabelStack(labelStack);  // Pop labels from the stack
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
 UNTIL LPAREN FINAL_EXP 
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
//     IF LPAREN FINAL_EXP RPAREN LBRACE MATCHED_IF RBRACE ELSE LBRACE MATCHED_IF RBRACE
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
    IF LPAREN FINAL_EXP RPAREN LBRACE
    {
        // Start a new scope for the if block
        enterScope();
        SymbolTableEntry *condition = $3; // Assuming FINAL_EXP returns a SymbolTableEntry*
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
    // |
    // IF LPAREN FINAL_EXP RPAREN STMT
    // {
    //     SymbolTableEntry *condition = $3;
    //     unmatchedIfQuadruple(condition, NULL, NULL, true);
    // }
; 
ASSIGNMENT : ID ASSIGN FINAL_EXP SEMICOLON
    { 
        SymbolTableEntry *entry = lookupSymbol($1);
        if (!entry) {
           char errorMsg[256];
            if (currentFunction) {
                sprintf(errorMsg, "Variable '%s' not declared in the current scope of function '%s'", $1, currentFunction->name);
            } else {
                sprintf(errorMsg, "Variable '%s' not declared in the current scope", $1);
            }
            semanticError(errorMsg);
        } else {

            if (entry->isTemp) {
                semanticError("Cannot assign a value to a function.");
            }

            if (strcmp(($3)->type, "void") == 0) {
                semanticError("void value cannot be assigned to a variable");
            }
            else if (strcmp(entry->type, ($3)->type) != 0) {
                semanticError("Type mismatch in assignment");
            }
            else {
                $$ = addQuadruple("ASSIGN", entry, $3);
                updateSymbolValue($1, ($3)->value);
                entry->isInitialized = 1;  
            }
        }
        $$ = $3;
    }            
;

ASSIGNMENT_FORLOOP : ID ASSIGN FINAL_EXP 
    { 
        printf("hebaaaaaaaaa");
        // Assign the value of EXP to the variable ID
        // assign_var($1, $3); 
        bool isVoid = strcmp(($3)->type, "void") == 0;
                if (isVoid) {
                    semanticError("void value cannot be assigned to a variable");
                }
        SymbolTableEntry *entry = lookupSymbol($1);
        printf("entrry->name %s\n", entry->name);
        if (!entry) {
            semanticError("Variable not declared in any scope");
        } else {
            if(entry->isTemp){
                semanticError("Cannot assign a value to a function.");
            }
            //check types before assigning
            if (strcmp(entry->type, ($3)->type) != 0) {
                semanticError("Type mismatch in assignment");
            }
            
            $$ = addQuadruple("ASSIGN", entry, $3);
            updateSymbolValue($1, ($3)->value);
            entry->isInitialized = 1;  // Mark the variable as initialized
        }
        $$ = $3;
    }            
;



FINAL_EXP : LOGICAL_EXP 
            { $$ = $1; 
            if(currentFunction){
                currentFunction->returnVar = ($1)->name;
            }
            }
            
            ;

LOGICAL_EXP : LOGICAL_EXP OR  REL_EXP  { $$ = addQuadruple("OR", $1, $3); }
            | LOGICAL_EXP AND REL_EXP  { $$ = addQuadruple("AND", $1, $3); }
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
            semanticError("Division by zero"); 
            exit(1); 
         } else {
            $$ = addQuadruple("DIV", $1, $3);
            printf("Dividing %s by %s\n", ($1)->name, ($3)->name);
         }
     }
      
     | TERM MOD POWER    { $$ = addQuadruple("MOD", $1, $3); }
     | POWER                { $$ = $1; }
     ;

POWER : FACTOR POW POWER    { $$ = addQuadruple("POW", $1, $3); }
      | FACTOR              { $$ = $1; }
      ;

FACTOR : LPAREN FINAL_EXP RPAREN 
        { 
            $$ = $2; 
            printf("Logical expression evaluated.\n"); 
        }
       | SUB FACTOR          
        { 
            printf("Negation applied: %f\n", $$); 
        
            $$ = addQuadruple("NEG", $2, NULL);
            printf("Negation applied2: %f\n", $$);
        }
       | NOT FACTOR          
        { 
            $$ = addQuadruple("NOT", $2, NULL);
            printf("Logical NOT applied: %d\n", $$); 
        }
       | INTEGER             
        { 
            SymbolTableEntry *entry = lookupSymbol($1);
            if (!entry) {
                $$ = addSymbol($1, "int", false,true);
            }
            else
            $$ = entry;
            printf("Integer constant: %s\n", $1); 
        }
       | FLOAT               
        { 
            SymbolTableEntry *entry = lookupSymbol($1);
            if (!entry) {
                $$ = addSymbol($1, "float", false,true);
            } else
            $$ = entry;
            printf("Float constant: %s\n", $1);
        }
       | CHAR                
        { 
            SymbolTableEntry *entry = lookupSymbol($1);
            if (!entry) {
                $$ = addSymbol($1, "char", false,true);
            } else
            $$ = entry;
            printf("Character constant: %s\n", $1);
        }
        | STRING
        {
            printf("String constant: %s\n", $1);
            SymbolTableEntry *entry = lookupSymbol($1);
            if (!entry) {
                $$ = addSymbol($1, "string", false,true);
            } else
            $$ = entry;
            printf("String constant: %s\n", $1);
        }
       | ID                  
        { 
            // TODO: understand this errors 
            // Look up the variable in the symbol table
            SymbolTableEntry *entry = lookupSymbol($1);
            if (!entry) {
                char errorMsg[256];
                sprintf(errorMsg, "Variable '%s' not declared in the current scope", $1);
                semanticError(errorMsg);
            } else {
                if (!entry->isInitialized && !entry->isUsed ) {
                    if(entry->isTemp){
                        yyerror("Invalid function call , missing parenthesis ");
                    }else{

                        semanticError("Variable used before initialization");
                    }
                }
                entry->isUsed = 1;  // Mark the variable as used
                $$ = lookupSymbol($1);  // Retrieve its runtime value
                printf("Variable '%s' of type '%s' used at line %d. Value: %f\n", $1, entry->type, yylineno, $$);                   }
        }
        |  FUNCTION_CALL 
            { 
                
                $$ = $1;
                if(currentFunction){
                    currentFunction->returnVar = ($1)->name;
                }

            }
       ;
%% 

void yyerror(const char *s) {
    FILE *errorFile = fopen("syntax_err.txt", "a");
    if (errorFile == NULL) {
        fprintf(stderr, "Error opening syntax_err.txt for writing!\n");
        return;
    }
    fprintf(errorFile, "Syntax error: %s at line %d\n", s, yylineno);
    fclose(errorFile);
    fprintf(stderr, "Syntax error: %s at line %d\n", s, yylineno);
}

void clearFile(const char *filename) {
        FILE *file = fopen(filename, "w");
        if (file == NULL) {
            fprintf(stderr, "Error opening %s for writing!\n", filename);
            return;
        }
        fclose(file);
    }

int main(int argc, char **argv) {

    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror(argv[1]);
            return 1;
        }
    } 
    
    clearFile("syntax_err.txt");
    clearFile("semantic_err.txt");
    clearFile("quadruples.txt");
    clearFile("symbol_table.txt");

    if (yyparse() == 0) {
        printf("Parsing successful\n");
        printQuadruples();
        

    } else {
        printf("Parsing failed\n");
    }
    writeSymbolTableOfAllScopesToFile();
    checkUnusedVariables();
    return 0;
}
