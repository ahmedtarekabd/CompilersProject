%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    void yyerror(const char *s);
    int yylex(void);
    extern FILE *yyin;

    // Enum to represent data types
    typedef enum {
        TYPE_INT,
        TYPE_FLOAT,
        TYPE_CHAR
    } DataType;

    // Struct to represent a symbol table entry
    typedef struct {
        char name[100];
        DataType type;
        union {
            int i_val;
            float f_val;
            char c_val;
        } value;
    } SymbolTableEntry;

    #define MAX_VARS 100
    SymbolTableEntry symbol_table[MAX_VARS]; // array to store symbol table entries
    int var_count = 0; // to keep track of how many variables we've added

    // Function to get the value of a variable
    int get_var_value(char *var_name) {
        for (int i = 0; i < var_count; i++) {
            if (strcmp(symbol_table[i].name, var_name) == 0) {
                if (symbol_table[i].type == TYPE_INT) {
                    return symbol_table[i].value.i_val;
                } else if (symbol_table[i].type == TYPE_FLOAT) {
                    return (int)symbol_table[i].value.f_val;
                } else if (symbol_table[i].type == TYPE_CHAR) {
                    return (int)symbol_table[i].value.c_val;
                }
            }
        }
        printf("Variable not found: %s\n", var_name);
        return 0; // default value if not found
    }

    // Function to assign a value to a variable
    void assign_var(char *var_name, int value, DataType type) {
        for (int i = 0; i < var_count; i++) {
            if (strcmp(symbol_table[i].name, var_name) == 0) {
                symbol_table[i].type = type;
                if (type == TYPE_INT) {
                    symbol_table[i].value.i_val = value;
                } else if (type == TYPE_FLOAT) {
                    symbol_table[i].value.f_val = (float)value;
                } else if (type == TYPE_CHAR) {
                    symbol_table[i].value.c_val = (char)value;
                }
                return;
            }
        }
        // If the variable does not exist, add it to the symbol table
        strcpy(symbol_table[var_count].name, var_name);
        symbol_table[var_count].type = type;
        if (type == TYPE_INT) {
            symbol_table[var_count].value.i_val = value;
        } else if (type == TYPE_FLOAT) {
            symbol_table[var_count].value.f_val = (float)value;
        } else if (type == TYPE_CHAR) {
            symbol_table[var_count].value.c_val = (char)value;
        }
        var_count++;
    }

%}

%union {
    int i;
    char c;
    float f;
    char *s;
}

%token POW NOT OR AND EQ NE LT LE GT GE ASSIGN LPAREN RPAREN LBRACE RBRACE SEMICOLON
%token IF ELSE SWITCH INT FLOAT CHAR
%token SUB ADD DIV MUL
%token <i> INTEGER
%token <f> FLOAT
%token <c> CHAR
%token <s> ID

%type <i> EXP TERM FACTOR REL_EXP LOGICAL_EXP STMT ASSIGNMENT

%%

/* Production rules */
STMTS : STMTS STMT SEMICOLON { /* Handle multiple statements */ }
      | STMT SEMICOLON       { /* Handle a single statement */ }
      ; 
      
STMT : LOGICAL_EXP                   { printf("%d\n", $1); }
     | ASSIGNMENT                     { /* Assignment is handled in the action */ }
     ;

ASSIGNMENT : ID ASSIGN EXP            { 
                                        // Assign the value of EXP to the variable ID
                                        assign_var($1, $3, TYPE_INT); 
                                        printf("%s = %d\n", $1, $3); // For debugging
                                      }
          ;

LOGICAL_EXP : REL_EXP OR LOGICAL_EXP   { $$ = $1 || $3; }
            | REL_EXP AND LOGICAL_EXP  { $$ = $1 && $3; }
            | REL_EXP                  { $$ = $1; }
            ;

REL_EXP : EXP EQ EXP         { $$ = $1 == $3; }
        | EXP NE EXP         { $$ = $1 != $3; }
        | EXP LT EXP         { $$ = $1 < $3; }
        | EXP LE EXP         { $$ = $1 <= $3; }
        | EXP GT EXP         { $$ = $1 > $3; }
        | EXP GE EXP         { $$ = $1 >= $3; }
        | EXP                { $$ = $1; }
        ;

EXP : EXP ADD TERM           { $$ = $1 + $3; }
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
       | INTEGER             { $$ = $1;}
       | FLOAT               { $$ = $1; }
       | CHAR                { $$ = $1; }
       | ID                   { $$ = get_var_value($1); } /* Retrieve the variable value */
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