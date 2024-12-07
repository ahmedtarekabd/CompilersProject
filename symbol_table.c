#include "symbol_table.h"

SymbolTableEntry symbol_table[MAX_VARS]; // array to store symbol table entries
int var_count = 0; // to keep track of how many variables we've added

// Function to get the value of a variable
int get_var_value(char *var_name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(symbol_table[i].name, var_name) == 0) {
            if (symbol_table[i].type == TYPE_INT) {
                printf("Found %d\n", symbol_table[i].value.i_val);
                return symbol_table[i].value.i_val;
            } else if (symbol_table[i].type == TYPE_FLOAT) {
                printf("Found %f\n", symbol_table[i].value.f_val);
                return (int)symbol_table[i].value.f_val;
            } else if (symbol_table[i].type == TYPE_CHAR) {
                return (int)symbol_table[i].value.c_val;
            }
        }
    }
    printf("Variable not found: %s\n", var_name);
    return 0; // default value if not found
}

// Function to put an entry in the symbol table
bool put_var(char *var_name, DataType type) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(symbol_table[i].name, var_name) == 0) {
            printf("Variable already exists: %s\n", var_name);
            return false ;
        }
    }
    strcpy(symbol_table[var_count].name, var_name);
    printf("Added %s to symbol table with value %d\n", var_name, symbol_table[var_count].value.f_val);
    symbol_table[var_count].type = type;
    var_count++; 
    return true;
}

DataType get_var_type(char *var_name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(symbol_table[i].name, var_name) == 0) {
            return symbol_table[i].type;
        }
    }
    return TYPE_UNKNOWN;
}

// Function to assign a value to a variable
void assign_var(char *var_name, float value) {
    DataType type = get_var_type(var_name);
    for (int i = 0; i < var_count; i++) {
        if (strcmp(symbol_table[i].name, var_name) == 0) {
            symbol_table[i].type = type;
            if (type == TYPE_INT) {
                symbol_table[i].value.i_val = (int)value;
            } else if (type == TYPE_FLOAT) {
                symbol_table[i].value.f_val = value;
            } else if (type == TYPE_CHAR) {
                symbol_table[i].value.c_val = (char)value;
            }
            printf("Assigned %f to %s\n", symbol_table[i].value.f_val, var_name);
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