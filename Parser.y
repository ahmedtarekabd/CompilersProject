%{
    #include <stdio.h>
    #include <stdlib.h>

    void yyerror(const char *s);
    int yylex(void);
    extern FILE *yyin;

%}
%union {
    int i;
}
%token POW NOT OR AND EQ NE LT LE GT GE ASSIGN LPAREN RPAREN LBRACE RBRACE SEMICOLON
%token IF ELSE SWITCH INT FLOAT CHAR
%token SUB ADD DIV MUL
%token <i> INTEGER
%type <i> EXP TERM FACTOR REL_EXP LOGICAL_EXP STMT


/* Production rules */
%%
STMT : EXP                   { printf("%d\n", $1); }
     ;

/* Logical expressions have the lowest precedence */
LOGICAL_EXP : REL_EXP OR LOGICAL_EXP   { $$ = $1 || $3; }
            | REL_EXP AND LOGICAL_EXP  { $$ = $1 && $3; }
            | REL_EXP                  { $$ = $1; }
            ;

/* Comparison expressions (medium precedence) */
REL_EXP : EXP EQ EXP         { $$ = $1 == $3; }
        | EXP NE EXP         { $$ = $1 != $3; }
        | EXP LT EXP         { $$ = $1 < $3; }
        | EXP LE EXP         { $$ = $1 <= $3; }
        | EXP GT EXP         { $$ = $1 > $3; printf("hiii\n"); }
        | EXP GE EXP         { $$ = $1 >= $3; }
        | EXP                { $$ = $1; }
        ;

/* Arithmetic expressions (highest precedence) */
EXP : EXP ADD TERM           { $$ = $1 + $3; }
    | EXP SUB TERM           { $$ = $1 - $3; }
    | TERM                   { $$ = $1; }
    ;

TERM : TERM MUL FACTOR       { $$ = $1 * $3; printf("multiply\n") }
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

FACTOR : '(' LOGICAL_EXP ')' { $$ = $2; }
       | SUB FACTOR          { $$ = -$2; }
       | NOT FACTOR          { $$ = !$2; }
       | INTEGER             { $$ = $1;printf("jojo")}
       ;
%%

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(int argc, char **argv) {
 if (argc >1) {
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
