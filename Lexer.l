%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>  // Include this header for strdup
    #include "Parser.tab.h"
    
    #include "symbol_table.h"

%}


%%
"for"       { return FOR; }
"while"     { return WHILE; }
"repeat"    { return REPEAT; }
"until"     { return UNTIL; }
"switch"    { return SWITCH; }
"case"      { return CASE; }
"default"   { return DEFAULT; }
"break"     { return BREAK; }
"return"    { return RETURN; }
"if"        { return IF; }
"else"      { return ELSE; }

"void"      { return VOID_TYPE; }
"int"       { return INT_TYPE; }
"float"     { return FLOAT_TYPE; }
"char"      { return CHAR_TYPE; }
"const"     { return CONST; }


[0-9]+\.[0-9]+  { yylval.f = atof(yytext); printf("Float: %f\n", yylval.f); return FLOAT_VALUE; }
[0-9]+      { yylval.i = atoi(yytext); return INTEGER_VALUE; }
\b'[a-zA-Z_]'\b     { yylval.c = yytext[1]; return CHAR_VALUE; }
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
":"         { return COLON; }
","         { return COMMA; }




%%

int yywrap(void) {
    return 1;
}