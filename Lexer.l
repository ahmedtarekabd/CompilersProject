%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>  // Include this header for strdup
    #include "symbol_table.h"
    #include "Parser.tab.h"
    

%}
%option yylineno

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
"string"    { return STRING_TYPE; }
"const"     { return CONST; }


[0-9]+\.[0-9]+  { yylval.s = yytext; printf("Float: %f\n", yylval.f); return FLOAT; }
[0-9]+      { yylval.s = yytext; return INTEGER; } 

[ \t\n]     { /* Ignore whitespace */ }
#.*    { /* Ignore comments */ }
\/\/.*    { /* Ignore comments */ }

\"[^"]*\" { yylval.s = strdup(yytext); return STRING; }
\'[^\']\' { yylval.s = strdup(yytext); return CHAR; }
\'[^']*\' { yylval.s = strdup(yytext); return STRING; }


[a-zA-Z_][a-zA-Z0-9_]* { yylval.s = strdup(yytext); return ID; }  // Adjusted identifier rule



"+"         { return ADD; }
"-"         { return SUB; }
"*"         { return MUL; }
"/"         { return DIV; }
"^"         { return POW; }
"%"         { return MOD; }

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