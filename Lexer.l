%{
    #include <stdio.h>
    #include <stdlib.h>

    #include "Parser.tab.h"

%}

%%
[0-9]+      { yylval.i = atoi(yytext); return INTEGER; }
[ \t\n]     { }
[()+-/*]    { return yytext[0]; }



%%

int yywrap(void) {
    return 1;
}

