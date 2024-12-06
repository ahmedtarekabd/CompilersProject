%{
    #include <stdio.h>
    #include <stdlib.h>

    void yyerror(const char *s);
    int yylex(void);

%}
%union {
    int i;
}
%token <i> INTEGER
%type <i> E T F
/* Production rules*/
%%
S : E           {printf("%d\n", $1);}
;
E : E '+' T     {$$ = $1 + $3;}
| E '-' T       {$$ = $1 - $3;}
| T             {$$ = $1;}
;
T : T '*' F     {$$ = $1 * $3;}
| T '/' F       {if ($3 == 0) {yyerror("Division by zero");} else $$ = $1 / $3;}
| F             {$$ = $1;}
;
F : '(' E ')'   {$$ = $2;}
| '-' F         {$$ = -$2;}
| INTEGER       {$$ = $1;}
;


%%

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
  yyparse();
  return 0;
}
