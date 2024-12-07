%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>  // Include this header for strdup
    #include "Parser.tab.h"
%}

%%
[0-9]+      { yylval.i = atoi(yytext); return INTEGER; }
[ \t\n]     { /* Ignore whitespace */ }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.s = strdup(yytext); return ID; }  // Adjusted identifier rule
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