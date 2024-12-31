%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include "quadruple.h"
    #include"utils/helper_functions.h"
    #include"utils/generic_stack.h"
    #include"utils/data_structures.h"
    
    /* Globals */ 
    extern FILE *yyin;
    char *currentSwitchVar;
    char* nextLabel;
    char* endLabel; 
    FunctionDef *currentFunction;
    GenericStack * labelStack  ;
    GenericStack * forLoopStack;
    FunctionDef *functionDefinitions[200];
    int functionsCount = 0;
    /* For function calls */
    SymbolTableEntry * currentFunctionParams[100];
    int currentFunctionParamsCount = 0;
    /* Functions */
    int yylex(void);
    void yyerror(const char *s) ;
%}
%union {
    int i;
    char c;
    float f;
    char *s;  
    char *Dtype;
    SymbolTableEntry *symbolTableEntry;
}
/* Logical operators */
%token  NOT OR AND  
/* Rel operators */
%token EQ NE LT LE GT GE ASSIGN 
/* General */
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON COLON 
%token RETURN COMMA 
%token ERROR
/* Loops */
%token FOR WHILE REPEAT UNTIL
/* Conditional statements */
%token IF ELSE SWITCH CASE BREAK DEFAULT
/* Mathematical operations*/
%token SUB ADD DIV MUL MOD POW
/* DataTypes */
%token INT_TYPE FLOAT_TYPE CHAR_TYPE VOID_TYPE CONST STRING_TYPE



%token <s> INTEGER
%token <s> FLOAT
%token <s> CHAR
%token <s> ID
%token <s> STRING

%type <symbolTableEntry> FINAL_EXP REL_EXP BLOCK FOR_LOOP ASSIGNMENT_FOR_LOOP_END WHILE_LOOP REPEAT_UNTIL_LOOP MATCHED_IF UNMATCHED_IF LOGICAL_EXP
%type <symbolTableEntry> EXP TERM FACTOR POWER 
%type <symbolTableEntry> STMT STMTS ASSIGNMENT DECLARATION CONST_DECLARATION ASSIGNMENT_FORLOOP 
%type <symbolTableEntry> FUNCTION_DEFINITION   PARAMS PARAM FUNCTION_BODY FUNCTION_PARAMS FUNCTION_PARAM FUNCTION_START VOID_FUNCTION_BODY FUNCTION_CALL
%type <Dtype> PARAM_TYPE 

%%

/* Production rules */

STMTS : STMTS STMT  { /* Handle multiple statements */ }
      | STMT        { /* Handle a single statement */ }
      | ERROR       { fprintf(stderr, "Syntax error: Skipping invalid statement.\n"); yyerror; }
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
            initializeCurrentFunction(&currentFunction,$2, "void");
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
    RBRACE  {
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
  
        }
        |
        ;

PARAMS: PARAMS COMMA PARAM
      | PARAM
      ;
PARAM : PARAM_TYPE ID {
          
            SymbolTableEntry *entry = lookupSymbol($2);
            if (entry) {
                semanticError("Variable already declared in this scope");
            } else {
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
        initializeCurrentFunction(&currentFunction,$2, $1);
    }
}
FUNCTION_CALL:  ID LPAREN FUNCTION_CALL_PARAMS RPAREN 
    {
        SymbolTableEntry *entry = lookupSymbol($1);
        if (!entry) {
            semanticError("Function not declared in any scope");
        } else {
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
        SymbolTableEntry *switchVar = lookupSymbol(currentSwitchVar);
        SymbolTableEntry *caseVar = addSymbol($2, "int", false,false);
        SymbolTableEntry *condition = addQuadruple("EQ", switchVar, caseVar);
        nextLabel = newLabel();
        switchcaseQuadruple(condition , nextLabel ,endLabel, true,false);

    }
    STMTS 
    {
    
        switchcaseQuadruple(NULL , nextLabel ,endLabel, false,false); 
    }
    BREAK SEMICOLON
    |
    CASE CHAR COLON 
    {
  
        SymbolTableEntry *switchVar = lookupSymbol(currentSwitchVar);
        SymbolTableEntry *caseVar = addSymbol($2, "int", false,false);
        SymbolTableEntry *condition = addQuadruple("EQ", switchVar, caseVar);
        nextLabel = newLabel();
        switchcaseQuadruple(condition , nextLabel ,endLabel, true,false);

    }
    STMTS 
    {
     
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

FOR_LOOP: FOR LPAREN ASSIGNMENT_FORLOOP SEMICOLON 
{
    Labels *labels = createLabels(2);
    push(&labelStack, labels); 
    addQuadrupleLabel(NULL, labels->loopLabel,NULL, true);
}
FINAL_EXP SEMICOLON
{
            // Start a new scope for the loop
            
            SymbolTableEntry *condition = $6; 
            Labels *labels = pop(labelStack); 
            addQuadrupleLabel(condition, labels->loopLabel, labels->exitLabel, true);
            push(&labelStack, labels);  
            
            
        }
 ASSIGNMENT_FOR_LOOP_END RPAREN 
        LBRACE
        {
            enterScope();
        }
        STMTS 
        RBRACE
        {   
            Labels *labels = pop(labelStack);  
            ForLoopAttributes *forLoopAttributes = pop(forLoopStack);
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
        bool isVoid = strcmp(($3)->type, "void") == 0;
                if (isVoid) {
                    semanticError("void value cannot be assigned to a variable");
                }
        SymbolTableEntry *entry = lookupSymbol($1);
        if (!entry) {
            semanticError("Variable not declared in any scope");
        } else {
            if(entry->isTempVarOrFunction){
                semanticError("Cannot assign a value to a function.");
            }
            if (strcmp(entry->type, ($3)->type) != 0) {
                semanticError("Type mismatch in assignment");
            }
            SymbolTableEntry *entry = lookupSymbol($1);
            if(!entry){ 
                char message[256];
                sprintf(message, " Variable %s is not declared in the current scope",($1));
                semanticError(message);
                exit(1);
            }
            ForLoopAttributes *forLoopAttributes = createForLoopAttributes(entry->name, ($3)->name, entry->type, ($3)->type);
            push(&forLoopStack, forLoopAttributes);
            entry->isInitialized = 1;  
        }
        $$ = $3;
    }            
;


WHILE_LOOP: WHILE LPAREN 
{
    Labels *labels = createLabels(2);
            push(&labelStack, labels);
            addQuadrupleLabel(NULL, labels->loopLabel,NULL, true);
}

FINAL_EXP RPAREN LBRACE
   {
            enterScope();
            SymbolTableEntry *condition = $4; 
            Labels *labels = pop(labelStack); 
            addQuadrupleLabel(condition, labels->loopLabel, labels->exitLabel, true);
            push(&labelStack, labels); 
        }
 STMTS RBRACE
     {   
            Labels *labels = pop(labelStack);
            addQuadrupleLabel(NULL, labels->loopLabel, labels->exitLabel, false);
            free(labels);
            exitScope();
        }
;
REPEAT_UNTIL_LOOP: REPEAT LBRACE 
{
    enterScope();
    Labels *labels = createLabels(1);
    
    push(&labelStack, labels); 
    addQuadrupleLabel(NULL, labels->loopLabel, NULL, true);
}
STMTS RBRACE
 UNTIL LPAREN FINAL_EXP 
 {
    SymbolTableEntry *condition = $8;
    Labels *labels = pop(labelStack);  
    addQuadrupleLabel(condition, labels->loopLabel, NULL, false);
    free(labels);
    exitScope();
}
 RPAREN SEMICOLON
    
;

MATCHED_IF : 
UNMATCHED_IF
ELSE LBRACE
    {
        enterScope();
        Labels *labels = createLabels(0);
        matchedIfQuadruple( labels->exitLabel, true);
        push(&labelStack, labels);  
    }
    STMTS RBRACE   
    {
        Labels *labels = pop(labelStack);  
        matchedIfQuadruple( labels->exitLabel, false);
        free(labels);
        exitScope();
    }
    ; 

UNMATCHED_IF:
    IF LPAREN FINAL_EXP RPAREN LBRACE
    {
        enterScope();
        SymbolTableEntry *condition = $3; 
        Labels *labels = createLabels(2);
        unmatchedIfQuadruple(condition, labels->loopLabel, labels->exitLabel, true);
        push(&labelStack, labels);  
    } STMTS RBRACE
    {
        Labels *labels = pop(labelStack);  
        unmatchedIfQuadruple(NULL, labels->loopLabel, labels->exitLabel, false);
        free(labels);
        exitScope();
    }
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

            if (entry->isTempVarOrFunction) {
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
                updateSymbolValue($1, atof(($3)->name));
                entry->isInitialized = 1;  
            }
        }
        $$ = $3;
    }            
;

ASSIGNMENT_FORLOOP : ID ASSIGN FINAL_EXP 
    { 
      
        bool isVoid = strcmp(($3)->type, "void") == 0;
                if (isVoid) {
                    semanticError("void value cannot be assigned to a variable");
                }
        SymbolTableEntry *entry = lookupSymbol($1);
        printf("entrry->name %s\n", entry->name);
        if (!entry) {
            semanticError("Variable not declared in any scope");
        } else {
            if(entry->isTempVarOrFunction){
                semanticError("Cannot assign a value to a function.");
            }
            //check types before assigning
            if (strcmp(entry->type, ($3)->type) != 0) {
                semanticError("Type mismatch in assignment");
            }
            
            $$ = addQuadruple("ASSIGN", entry, $3);
            updateSymbolValue($1, ($3)->value);
            entry->isInitialized = 1;  
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
            SymbolTableEntry *entry = lookupSymbol($1);
            if (!entry) {
                char errorMsg[256];
                sprintf(errorMsg, "Variable '%s' not declared in the current scope", $1);
                semanticError(errorMsg);
            } else {
                if (!entry->isInitialized && !entry->isUsed ) {
                    if(entry->isTempVarOrFunction){
                        yyerror("Invalid function call , missing parenthesis ");
                    }else{

                        semanticError("Variable used before initialization");
                    }
                }
                entry->isUsed = 1;      
                $$ = lookupSymbol($1);  
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
    FILE *errorFile = fopen("output_files/syntax_err.txt", "a");
    if (errorFile == NULL) {
        fprintf(stderr, "Error opening output_files/syntax_err.txt for writing!\n");
        return;
    }
    fprintf(errorFile, "Syntax error: %s at line %d\n", s, yylineno);
    fclose(errorFile);
    fprintf(stderr, "Syntax error: %s at line %d\n", s, yylineno);
}
int main(int argc, char **argv) {

    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            perror(argv[1]);
            return 1;
        }
    } 
    clearFile("output_files/syntax_err.txt");
    clearFile("output_files/semantics.txt");
    clearFile("output_files/quadruples.txt");
    clearFile("output_files/symbol_table.txt");
    labelStack = createStack();
    forLoopStack = createStack();
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
