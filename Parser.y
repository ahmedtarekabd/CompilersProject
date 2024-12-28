%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include "symbol_table.h"  // Include the symbol table header
    #include "quadruple.h"  // Include the quadruple header

    void yyerror(const char *s);
    int yylex(void);
    extern FILE *yyin;
    
%}

%union {
    int i;
    char c;
    float f;
    char *s;  
    int type;  // Add a new member for data type
}

%token POW NOT OR AND EQ NE LT LE GT GE ASSIGN LPAREN RPAREN LBRACE RBRACE SEMICOLON COLON
%token FOR WHILE REPEAT UNTIL
%token IF ELSE SWITCH CASE BREAK DEFAULT
%token SUB ADD DIV MUL
%token INT_TYPE FLOAT_TYPE CHAR_TYPE VOID_TYPE CONST
%token RETURN COMMA 
%token ERROR


%token <i> INTEGER_VALUE
%token <f> FLOAT_VALUE
%token <c> CHAR_VALUE
%token <s> ID

%type <s> LOGICAL_EXP REL_EXP
%type <s> EXP TERM FACTOR POWER//FUNCTION_STMTS
%type <s> STMT STMTS ASSIGNMENT DECLARATION CONST_DECLARATION
// %type <i> MATCHED_IF UNMATCHED_IF 
%type <i> FOR_LOOP WHILE_LOOP REPEAT_UNTIL_LOOP SWITCH_CASE CASES CASE_BLOCK
// %type <i> FUNCTION_DECL FUNCTION_BODY  PARAMS PARAM
%type <type> PARAM_TYPE //RETURN_TYPE



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
    // | UNMATCHED_IF  
    // | 
    SWITCH_CASE 
    | FOR_LOOP    
    | WHILE_LOOP        
    | REPEAT_UNTIL_LOOP   
    // | FUNCTION_DECL SEMICOLON
    // | FUNCTION_DECL FUNCTION_BODY
    | BLOCK
    | DECLARATION 
    | CONST_DECLARATION 
    | ASSIGNMENT           
    | LOGICAL_EXP SEMICOLON         { printf("%d\n", $1); }
    ;

DECLARATION: PARAM_TYPE ID SEMICOLON {
                if (lookupSymbol($2) && isSymbolDeclaredInCurrentScope($2)) {
                    yyerror("Variable already declared in this scope");
                } else {
                    Value value;
                    addSymbol($2, $1, false, value);  // Add variable to current scope
                }
            }
            ;

CONST_DECLARATION: CONST PARAM_TYPE ID SEMICOLON {
                if (lookupSymbol($3) && isSymbolDeclaredInCurrentScope($3)) {
                    yyerror("Variable already declared in this scope");
                } else {
                    Value value;
                    addSymbol($3, $2, true, value);  // Add variable to current scope
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


PARAM_TYPE: INT_TYPE        { $$ = INTEGER; }
          | FLOAT_TYPE      { $$ = FLOAT; }
          | CHAR_TYPE       { $$ = CHAR; }
          ;

// RETURN_TYPE: VOID_TYPE      
//            | PARAM_TYPE     
//            ;

SWITCH_CASE: SWITCH LPAREN ID RPAREN LBRACE CASES CASE_DEFAULT RBRACE
    {
        printf("Switch case\n");
        printf("Switch value: %f\n", $3);
        // switch ($3) {
        //     $6;
        //     default:
        //         $9;
        //         break;
        // }
    }
;
CASE_DEFAULT: DEFAULT COLON STMTS BREAK SEMICOLON
    {
        printf("Default case\n");
        // default:
        //     $4;
        //     break;
    }
    | 
    ;
CASES: CASES CASE_BLOCK
     | CASE_BLOCK
;

CASE_BLOCK: CASE INTEGER_VALUE COLON CASE_STMTS BREAK SEMICOLON
    {
        printf("Case %d\n", $2);
        // case $2:
        //     $4;
        //     break;
    }

;
CASE_STMTS: STMTS
          | 
          ;


FOR_LOOP: FOR LPAREN ASSIGNMENT SEMICOLON LOGICAL_EXP SEMICOLON ASSIGNMENT RPAREN LBRACE STMTS RBRACE
    {
        for ($3; $5; $7) {
            printf("For loop\n");
            $10;  
        }
    }
;
WHILE_LOOP: WHILE LPAREN LOGICAL_EXP RPAREN LBRACE STMTS RBRACE
    {
        while ($3) {
            printf("While loop\n");
            $6;  
        }
    }

;
REPEAT_UNTIL_LOOP: REPEAT LBRACE STMTS RBRACE UNTIL LPAREN LOGICAL_EXP RPAREN SEMICOLON
    {
        do {
            printf("Repeat until loop\n");
            $3;  
        } while (!$7);
    }
;
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

ASSIGNMENT : ID ASSIGN EXP SEMICOLON
    { 
        char* id = strdup($1);
        addQuadruple("=", $3, NULL, id);
        Value value;
        updateSymbolValue($1, value);
    }            
;

LOGICAL_EXP : REL_EXP OR LOGICAL_EXP { 
                char *temp = newTemp();
                addQuadruple("OR", $1, $3, temp);
                $$ = temp; 
            }
            | REL_EXP AND LOGICAL_EXP { 
                char *temp = newTemp();
                addQuadruple("AND", $1, $3, temp);
                $$ = temp; 
            }
            | REL_EXP { $$ = $1; }
            ;

REL_EXP : EXP EQ EXP { 
            char *temp = newTemp();
            addQuadruple("EQ", $1, $3, temp);
            $$ = temp; 
        }
        | EXP NE EXP { 
            char *temp = newTemp();
            addQuadruple("NE", $1, $3, temp);
            $$ = temp; 
        }
        | EXP LT EXP { 
            char *temp = newTemp();
            addQuadruple("LT", $1, $3, temp);
            $$ = temp; 
        }
        | EXP LE EXP { 
            char *temp = newTemp();
            addQuadruple("LE", $1, $3, temp);
            $$ = temp; 
        }
        | EXP GT EXP { 
            char *temp = newTemp();
            addQuadruple("GT", $1, $3, temp);
            $$ = temp; 
        }
        | EXP GE EXP { 
            char *temp = newTemp();
            addQuadruple("GE", $1, $3, temp);
            $$ = temp; 
        }
        | EXP { $$ = $1; }
        ;

EXP : EXP ADD TERM { 
            printf("Adding %s + %s\n", $1, $3);  // Debugging to check the operands
            char *temp1 = $1;  // Left operand (could be a temp)
            char *temp2 = $3;  // Right operand (could be another temp)
            char *resultTemp = newTemp();  // Create new temp for result
            addQuadruple("ADD", temp1, temp2, resultTemp);  // Use the correct operands
            $$ = resultTemp;  // Assign result to $$ (final result)
        }       

    | EXP SUB TERM { 
            char *temp = newTemp();
            addQuadruple("SUB", $1, $3, temp);
            $$ = temp; 
        }
    | TERM { $$ = $1; 
    printf("Term: %s\n", $$);
    }
    ;

TERM : TERM MUL POWER { 
            char *temp = newTemp();
            addQuadruple("MUL", $1, $3, temp);
            $$ = temp; 
        }
     | TERM DIV POWER { 
            if ($3 == 0) { 
                yyerror("Division by zero"); 
                exit(1); 
            } else {
                char *temp = newTemp();
                addQuadruple("DIV", $1, $3, temp);
                $$ = temp; 
            }
        }
     | POWER { $$ = $1; 
     
     printf("Power: %s\n", $$);
     }
     ;

POWER : FACTOR POW POWER { 
            char *temp = newTemp();
            addQuadruple("POW", $1, $3, temp);
            $$ = temp; 
        }
      | FACTOR { $$ = $1; 
      printf("Factor: %s\n", $$);
      }
      ;


FACTOR : LPAREN LOGICAL_EXP RPAREN 
        { 
            char *tempVar = newTemp();  // Generate a new temporary variable
            $$ = tempVar;  // The result of the logical expression will be stored in this temporary variable
            printf("Logical expression evaluated: %f\n", $$);
            // Add the quadruple for this logical expression
            addQuadruple("LPAREN", "Logical Expression", "", tempVar);
        }
      | SUB FACTOR          
        { 
            char *tempVar = newTemp();  // Generate a new temporary variable
            $$ = tempVar;  // Store the result in a temporary variable
            printf("Negation applied: %f\n", $$);
            // Add the quadruple for negation
            addQuadruple("SUB", "0", "$2", tempVar);
        }
      | NOT FACTOR          
        { 
            char *tempVar = newTemp();  // Generate a new temporary variable
            $$ = tempVar;  // Store the result in a temporary variable
            printf("Logical NOT applied: %d\n", $$);
            // Add the quadruple for logical NOT
            addQuadruple("NOT", "$2", "", tempVar);
        }
      | INTEGER_VALUE             
        { 
            char *tempVar = newTemp();  // Generate a new temporary variable
            $$ = tempVar;  // The result of the constant will be stored in this temporary variable
            printf("Integer constant: %d\n", $1);
            // Add the quadruple for integer constant
            addQuadruple("CONST", "", "", tempVar);
            // Add the constant to the symbol table
            Value value;
            value.intValue = $1;
            addSymbol($$, INTEGER, true, value);  // Add to symbol table with constant value
        }
      | FLOAT_VALUE               
        { 
            char *tempVar = newTemp();  // Generate a new temporary variable
            $$ = tempVar;  // The result of the constant will be stored in this temporary variable
            printf("Float constant: %f\n", $1);
            // Add the quadruple for float constant
            addQuadruple("CONST", "", "", tempVar);
            // Add the constant to the symbol table
            Value value;
            value.floatValue = $1;
            addSymbol($$, FLOAT, true, value);  // Add to symbol table with constant value
        }
      | CHAR_VALUE
        { 
            char *tempVar = newTemp();  // Generate a new temporary variable
            $$ = tempVar;  // The result of the constant will be stored in this temporary variable
            printf("Character constant: '%c'\n", $1);
            // Add the quadruple for character constant
            addQuadruple("CONST", "", "", tempVar);
            // Add the constant to the symbol table
            Value value;
            value.charValue = $1;
            addSymbol($$, CHAR, true, value);  // Add to symbol table with constant value
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
                $$ = entry->name;  // Use the variable's name for now, may need its value later
                printf("Variable '%s' of type '%s' used. Value: %f\n", $1, entry->type, entry->value);
                // Add the quadruple for the variable
                addQuadruple("ID", $1, "", "tempVar");
            }
        }
      ;





%% 

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
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
