#include "symbol_table.h"

SymbolTableEntry symbol_table[MAX_VARS]; // array to store symbol table entries
int var_count = 0; // to keep track of how many variables we've added

// Function to get the value of a variable
float get_var_value(char *var_name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(symbol_table[i].name, var_name) == 0) {
            if (symbol_table[i].type == TYPE_INT) {
                printf("Found %d\n", symbol_table[i].value.i_val);
                return symbol_table[i].value.i_val;
            } else if (symbol_table[i].type == TYPE_FLOAT) {
                printf("Found %f\n", symbol_table[i].value.f_val);
                return symbol_table[i].value.f_val;
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
    symbol_table[var_count].is_initialized = false;
    var_count++; 
    return true;
}

bool put_function(char *func_name, DataType return_type, DataType *param_types, int param_count) {
    if (var_count >= MAX_VARS) {
        printf("Error: Symbol table is full, cannot add function %s\n", func_name);
        return false;
    }

    for (int i = 0; i < var_count; i++) {
        if (strcmp(symbol_table[i].name, func_name) == 0) {
            printf("Error: Function or variable already exists with name %s\n", func_name);
            return false;
        }
    }

    // Add the function to the symbol table
    strcpy(symbol_table[var_count].name, func_name);
    symbol_table[var_count].type = return_type;
    symbol_table[var_count].is_function = true;
    symbol_table[var_count].func_info.param_count = param_count;

    // Copy parameter types
    for (int i = 0; i < param_count; i++) {
        symbol_table[var_count].func_info.param_types[i] = param_types[i];
    }

    printf("Added function %s to symbol table with return type %d\n", func_name, return_type);
    var_count++;
    return true;
}

DataType get_func_type(char *name, bool *is_function) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            *is_function = symbol_table[i].is_function;
            return symbol_table[i].type;
        }
    }
    return TYPE_UNKNOWN;
}

bool call_function(char *func_name, DataType *arg_types, int arg_count) {
    for (int i = 0; i < var_count; i++) {
        if (symbol_table[i].is_function && strcmp(symbol_table[i].name, func_name) == 0) {
            if (symbol_table[i].func_info.param_count != arg_count) {
                printf("Error: Function %s expects %d arguments but got %d\n",
                       func_name, symbol_table[i].func_info.param_count, arg_count);
                return false;
            }

            for (int j = 0; j < arg_count; j++) {
                if (symbol_table[i].func_info.param_types[j] != arg_types[j]) {
                    printf("Error: Parameter %d of function %s expects type %d but got %d\n",
                           j + 1, func_name, symbol_table[i].func_info.param_types[j], arg_types[j]);
                    return false;
                }
            }

            printf("Function %s called successfully.\n", func_name);
            return true;
        }
    }

    printf("Error: Function %s not found in symbol table.\n", func_name);
    return false;
}


DataType get_var_type(char *var_name) {
    for (int i = 0; i < var_count; i++) {
        if (strcmp(symbol_table[i].name, var_name) == 0) {
            return symbol_table[i].type;
        }
    }
    return TYPE_UNKNOWN;
}


void assign_var(char *var_name, float value) {
    DataType type = get_var_type(var_name);
    bool is_constant = (type == TYPE_CONST_CHAR || type == TYPE_CONST_INT || type == TYPE_CONST_FLOAT);

    // Check if the variable is constant and already initialized
    for (int i = 0; i < var_count; i++) {
        if (strcmp(symbol_table[i].name, var_name) == 0) {
            if (is_constant && symbol_table[i].is_initialized) {
                printf("Cannot assign value to constant variable: %s\n", var_name);
                return;
            }

            // Update the existing variable
            symbol_table[i].is_initialized = true;

            switch (type) {
                case TYPE_INT:
                case TYPE_CONST_INT:
                    symbol_table[i].value.i_val = (int)value;
                    printf("Assigned %d to %s\n", symbol_table[i].value.i_val, var_name);
                    break;
                case TYPE_FLOAT:
                case TYPE_CONST_FLOAT:
                    symbol_table[i].value.f_val = value;
                    printf("Assigned %.2f to %s\n", symbol_table[i].value.f_val, var_name);
                    break;
                case TYPE_CHAR:
                case TYPE_CONST_CHAR:
                    symbol_table[i].value.c_val = (char)value;
                    printf("Assigned '%c' to %s\n", symbol_table[i].value.c_val, var_name);
                    break;
                default:
                    printf("Error: Unsupported data type for %s\n", var_name);
                    return;
            }
            return;
        }
    }

    // If the variable does not exist, add it to the symbol table
    if (var_count < MAX_VARS) {
        strcpy(symbol_table[var_count].name, var_name);
        symbol_table[var_count].type = type;
        symbol_table[var_count].is_initialized = true;

        switch (type) {
            case TYPE_INT:
                symbol_table[var_count].value.i_val = (int)value;
                printf("Assigned %d to new variable %s\n", symbol_table[var_count].value.i_val, var_name);
                break;
            case TYPE_FLOAT:
                symbol_table[var_count].value.f_val = value;
                printf("Assigned %.2f to new variable %s\n", symbol_table[var_count].value.f_val, var_name);
                break;
            case TYPE_CHAR:
                symbol_table[var_count].value.c_val = (char)value;
                printf("Assigned '%c' to new variable %s\n", symbol_table[var_count].value.c_val, var_name);
                break;
            default:
                printf("Error: Unsupported data type for new variable %s\n", var_name);
                return;
        }
        var_count++;
    } else {
        printf("Error: Symbol table is full, cannot add variable %s\n", var_name);
    }
}
