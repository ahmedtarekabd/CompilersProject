%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symbol_table.h"  // Include the symbol table header

    void yyerror(const char *s);
    int yylex(void);
    extern FILE *yyin;
%}

%union {
    int i;
    char c;
    float f;
    char *s;  
}

%token POW NOT OR AND EQ NE LT LE GT GE ASSIGN LPAREN RPAREN LBRACE RBRACE SEMICOLON COLON
%token FOR WHILE REPEAT UNTIL
%token IF ELSE SWITCH CASE BREAK DEFAULT
%token SUB ADD DIV MUL
%token INT_TYPE FLOAT_TYPE CHAR_TYPE VOID_TYPE
%token RETURN COMMA 
%token ERROR


%token <i> INTEGER
%token <f> FLOAT
%token <c> CHAR
%token <s> ID

// %type <i> EXP TERM FACTOR REL_EXP LOGICAL_EXP STMT ASSIGNMENT STMTS
%type <i> LOGICAL_EXP REL_EXP
%type <f> EXP TERM FACTOR FUNCTION_STMTS
%type <i> STMT STMTS ASSIGNMENT
%type <i> MATCHED_IF UNMATCHED_IF FOR_LOOP WHILE_LOOP REPEAT_UNTIL_LOOP SWITCH_CASE CASES CASE_BLOCK
%type <i> FUNCTION_DECL FUNCTION_BODY  PARAMS PARAM
%type <s> PARAM_TYPE RETURN_TYPE

%%

/* Production rules */

STMTS : STMTS STMT  { /* Handle multiple statements */ }
      | STMT        { /* Handle a single statement */ }
      | ERROR       { fprintf(stderr, "Syntax error: Skipping invalid statement.\n"); yyerrok; }
      | BLOCK
      ;
      
BLOCK: LBRACE STMTS RBRACE
    {
        printf("Block parsed\n");
    }
    ;

STMT: MATCHED_IF                    
    | UNMATCHED_IF  
    | SWITCH_CASE 
    | FOR_LOOP    
    | WHILE_LOOP        
    | REPEAT_UNTIL_LOOP   
    | FUNCTION_DECL SEMICOLON
    | FUNCTION_DECL FUNCTION_BODY
    | ASSIGNMENT SEMICOLON          
    | LOGICAL_EXP SEMICOLON         { printf("%d\n", $1); }
    ;

FUNCTION_DECL: RETURN_TYPE ID LPAREN PARAMS RPAREN
    {
        printf("Function declaration\n");
        // Declare a function with the given return type, name, and parameters
        // declare_function($1, $2, $4);
    }
;

FUNCTION_BODY: LBRACE FUNCTION_STMTS RBRACE
    {
        printf("Function body parsed\n");
    }
    ;

FUNCTION_STMTS: STMTS RETURN EXP SEMICOLON
              | RETURN EXP SEMICOLON
              | RETURN SEMICOLON
              ;


PARAMS: PARAMS COMMA PARAM
      | PARAM
      | 
      ;

PARAM: PARAM_TYPE ID
    {
        printf("Parameter: Type: %s, Name: %s\n", $1, $2);
        // TODO: 
        // $$ = add_parameter($1, $2); // Add parameter to list
    }
    ;

PARAM_TYPE: INT_TYPE
          | FLOAT_TYPE
          | CHAR_TYPE
          ;

RETURN_TYPE: VOID_TYPE      
           | INT_TYPE       
           | FLOAT_TYPE     
           | CHAR_TYPE      
           ;

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

CASE_BLOCK: CASE INTEGER COLON CASE_STMTS BREAK SEMICOLON
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
MATCHED_IF: 
    IF LPAREN LOGICAL_EXP RPAREN LBRACE MATCHED_IF RBRACE ELSE LBRACE MATCHED_IF RBRACE
    {

        printf("matched 1");
        if ($3) {
            $$ = $6;  // Execute the first `if` branch
        } else {
            $$ = $10;  // Execute the second `else` branch
        }
    }
  | IF LPAREN LOGICAL_EXP RPAREN LBRACE STMT RBRACE ELSE LBRACE STMT RBRACE
    {
        printf("matched 2");
        if ($3) { 
            $$ = $6;  // Execute the `if` branch
        } else {
            $$ = $10;  // Execute the `else` branch
        }
    }
;


UNMATCHED_IF:
    IF LPAREN LOGICAL_EXP RPAREN LBRACE STMT RBRACE
    {
        printf("unmatched 1 %d\n", $3);
        if ($3 != 0) {
            $$ = $6;  // Execute the `if` branch
            printf("If statement executed\n");
        }
    }
  | IF LPAREN LOGICAL_EXP RPAREN LBRACE MATCHED_IF RBRACE ELSE LBRACE UNMATCHED_IF RBRACE
    {
        printf("unmatched 2");
        if ($3) {
            $$ = $6;  // Execute the nested `if`
        }
        else
        {
            $$ = $10;
        }
    }
;

ASSIGNMENT : ID ASSIGN EXP 
    { 
        // Assign the value of EXP to the variable ID

        assign_var($1, $3); 
    }             
;

LOGICAL_EXP : REL_EXP OR LOGICAL_EXP   { $$ = $1 || $3; }
            | REL_EXP AND LOGICAL_EXP  { $$ = $1 && $3; }
            | REL_EXP                  { $$ = $1;  }
            ;

REL_EXP : EXP EQ EXP         { $$ = $1 == $3; }
        | EXP NE EXP         { $$ = $1 != $3; }
        | EXP LT EXP         { $$ = $1 < $3; printf("LT %f %f is %d\n", $1, $3, $$); }
        | EXP LE EXP         { $$ = $1 <= $3; }
        | EXP GT EXP         { $$ = $1 > $3; printf("GT %f %f is %d\n", $1, $3, $$); }
        | EXP GE EXP         { $$ = $1 >= $3; }
        | EXP                { $$ = $1; }
        ;

EXP : EXP ADD TERM           { $$ = $1 + $3; printf("ADD %f %f\n", $1, $3); }
    | EXP SUB TERM           { $$ = $1 - $3; }
    | TERM                   { $$ = $1; }
    ;

TERM : TERM MUL FACTOR       { $$ = $1 * $3; }
     | TERM DIV FACTOR       { 
         if ($3 == 0) { 
             yyerror("Division by zero"); 
             exit(1); 
         } else {
             $$ = $1 / $3; 
         }
     }
     | FACTOR                { $$ = $1; }
     ;

FACTOR : LPAREN LOGICAL_EXP RPAREN { $$ = $2; }
       | SUB FACTOR          { $$ = -$2; }
       | NOT FACTOR          { $$ = !$2; }
       | INTEGER             { $$ = $1; }
       | FLOAT               { $$ = $1; }
       | CHAR                { $$ = $1; }
       | ID                  { $$ = get_var_value($1); printf("ID %s\n", $1); }
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
    } else {
        printf("Parsing failed\n");
    }
    return 0;
}