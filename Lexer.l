%{
    #include <stdio.h>
    #include <stdlib.h>

    #include "Parser.tab.h"
%}

%%
[0-9]+      { yylval.i = atoi(yytext); return INTEGER; }
[ \t\n]     { /* Ignore whitespace */ }
"+"         { return ADD; }
"-"         { return SUB; }
"*"         { return MUL; }
"/"         { return DIV; }
"^"         { return POW; }

"!"         { return NOT; }
"||"        { return OR; }
"&&"        { return AND; }
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















"if"        { return IF; }
"else"      { return ELSE; }
"switch"    { return SWITCH; }
"int"       { return INT; }
"float"     { return FLOAT; }
"char"      { return CHAR; }

%%

int yywrap(void) {
    return 1;
}