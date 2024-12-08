#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// Enum to represent data types
typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR,
    TYPE_CONST_INT,
    TYPE_CONST_FLOAT,
    TYPE_CONST_CHAR,
    TYPE_UNKNOWN
} DataType;

// Struct to represent a symbol table entry
typedef struct {
    char name[100];
    DataType type;
    bool is_function;
     union {
        struct {               // For variables
            int i_val;
            float f_val;
            char c_val;
        } value;

        struct {               // For functions
            DataType param_types[10]; // Types of the function's parameters
            int param_count;          // Number of parameters
        } func_info;
    };
    bool is_initialized;
} SymbolTableEntry;

#define MAX_VARS 100
extern SymbolTableEntry symbol_table[MAX_VARS]; // array to store symbol table entries
extern int var_count; // to keep track of how many variables we've added

// Function to get the value of a variable
float get_var_value(char *var_name);

bool put_var(char *var_name, DataType type);

// Function to assign a value to a variable
void assign_var(char *var_name, float value);

bool put_function(char *func_name, DataType return_type, DataType *param_types, int param_count);

bool call_function(char *func_name, DataType *arg_types, int arg_count);

#endif // SYMBOL_TABLE_H