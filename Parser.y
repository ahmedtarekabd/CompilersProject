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

%token POW NOT OR AND EQ NE LT LE GT GE ASSIGN LPAREN RPAREN LBRACE RBRACE SEMICOLON
%token IF ELSE SWITCH
%token SUB ADD DIV MUL
%token <i> INTEGER
%token <f> FLOAT
%token <c> CHAR
%token <s> ID

// %type <i> EXP TERM FACTOR REL_EXP LOGICAL_EXP STMT ASSIGNMENT STMTS
%type <i> LOGICAL_EXP REL_EXP
%type <f> EXP TERM FACTOR
%type <i> STMT STMTS ASSIGNMENT
%type <i> MATCHED_IF UNMATCHED_IF

%%

/* Production rules */

STMTS : STMTS STMT  { /* Handle multiple statements */ }
      | STMT        { /* Handle a single statement */ }
      ;

STMT: MATCHED_IF                    
    | UNMATCHED_IF                  
    | ASSIGNMENT SEMICOLON          
    | LOGICAL_EXP SEMICOLON         { printf("%d\n", $1); }
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
        printf("%s = %f\n", $1, $3); // For debugging
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
       | ID                  { $$ = get_var_value($1); } /* Retrieve the variable value */
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