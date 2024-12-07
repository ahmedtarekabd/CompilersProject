%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>  // Include this header for strdup
    #include "Parser.tab.h"
    #include "symbol_table.h"

%}


%%
"if"        { return IF; }
"else"      { return ELSE; }
[0-9]+\.[0-9]+  { yylval.f = atof(yytext); printf("Float: %f\n", yylval.f); return FLOAT; }
[0-9]+      { yylval.i = atoi(yytext); return INTEGER; }
[ \t\n]     { /* Ignore whitespace */ }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.s = strdup(yytext); return ID; }  // Adjusted identifier rule

int[ \t]+[a-zA-Z_][a-zA-Z0-9_]*([ \t]*)? {
    char *token = strdup(yytext + 3); // Skip "int"
    while (*token == ' ' || *token == '\t') token++; // Skip leading spaces

    char *var_name = strtok(token, " ");
    char *value = strtok(NULL, " ");
    yylval.s = var_name;
    if(put_var(var_name, TYPE_INT))
    {   
        if (value != NULL) {
            printf("Variable %s initialized to %d\n", var_name, atoi(value));
        } else {
            printf("Variable %s declared with default value 0\n", var_name);
        }
    }
    return ID;
    // else
    // {
    //     printf("heereeee");
    //     yyerror(strcat("Variable already declared: ",var_name));
    // }
}

float[ \t]+[a-zA-Z_][a-zA-Z0-9_]*([ \t]*)? {
    char *token = strdup(yytext + 5); // Skip "float"
    while (*token == ' ' || *token == '\t') token++; // Skip leading spaces

    char *var_name = strtok(token, " ");
    char *value = strtok(NULL, " ");
    yylval.s = var_name;
    put_var(var_name, TYPE_FLOAT);

    if (value != NULL) {
        printf("Variable %s initialized to %f\n", var_name, atof(value));
    } else {
        printf("Variable %s declared with default value 0.0\n", var_name);
    }
    return ID;
}

"+"         { return ADD; }
"-"         { return SUB; }
"*"         { return MUL; }
"/"         { return DIV; }
"^"         { return POW; }

"!"         { return NOT; }
"||"        { return OR; }
"&&"        { return AND;}
"=="        { return EQ; }
"!="        { return NE; }
"<"         { return LT; }
"<="        { return LE; }
">"         { return GT; }
">="        { return GE; }
"="         { return ASSIGN; }

"("         { return LPAREN; }
")"         { return RPAREN; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
";"         { return SEMICOLON; }





%%

int yywrap(void) {
    return 1;
}