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




[0-9]+\.[0-9]+  { yylval.f = atof(yytext); printf("Float: %f\n", yylval.f); return FLOAT; }
[0-9]+      { yylval.i = atoi(yytext); return INTEGER; }
[ \t\n]     { /* Ignore whitespace */ }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.s = strdup(yytext); return ID; }  // Adjusted identifier rule

const[ \t]+(int|float|char)[ \t]+[a-zA-Z_][a-zA-Z0-9_]*([ \t]*)? {
    char *token = strdup(yytext + 5); // Skip "const"
    while (*token == ' ' || *token == '\t') token++; // Skip leading spaces

    // Extract data type
    char *data_type = strtok(token, " ");
    DataType type;
    if (strcmp(data_type, "int") == 0) {
        type = TYPE_CONST_INT;
    } else if (strcmp(data_type, "float") == 0) {
        type = TYPE_CONST_FLOAT;
    } else if (strcmp(data_type, "char") == 0) {
        type = TYPE_CONST_CHAR;
    } else {
        printf("Error: Unknown data type '%s'.\n", data_type);
        return ERROR;
    }

    // Extract variable name
    char *var_name = strtok(NULL, " ");
    if (var_name == NULL) {
        printf("Error: Missing variable name.\n");
        return ERROR;
    }

    yylval.s = var_name;
    // Validate and add to symbol table
    if (put_var(var_name, type)) {
        printf("Constant %s of type %s declared.\n", var_name, data_type);
    }


    return ID;
}


(int|float|char)[ \t]+[a-zA-Z_][a-zA-Z0-9_]*([ \t]*)? {
    char *token = strdup(yytext); // Copy the entire matched string

    // Extract data type
    char *data_type = strtok(token, " ");
    DataType type;
    if (strcmp(data_type, "int") == 0) {
        type = TYPE_INT;
    } else if (strcmp(data_type, "float") == 0) {
        type = TYPE_FLOAT;
    } else if (strcmp(data_type, "char") == 0) {
        type = TYPE_CHAR;
    } else {
        fprintf(stderr, "Error: Unknown data type '%s'.\n", data_type);
        free(token);
        return ERROR; // Return an error token for invalid data types
    }

    // Extract variable name
    char *var_name = strtok(NULL, " ");
    if (var_name == NULL) {
        fprintf(stderr, "Error: Missing variable name after type '%s'.\n", data_type);
        free(token);
        return ERROR; // Return an error token for missing variable names
    }

    yylval.s = var_name;

    if (put_var(var_name, type)) {
        printf("Variable %s of type %s declared.\n", var_name, data_type);
    } else {
        fprintf(stderr, "Error: Variable %s could not be added to the symbol table.\n", var_name);
    }

    return ID; // Return a valid identifier token
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
":"         { return COLON; }
","         { return COMMA; }




%%

int yywrap(void) {
    return 1;
}