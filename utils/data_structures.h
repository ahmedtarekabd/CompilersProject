#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H
#include "data_structures.h"
/* Used by the parser in creating labels for if conditions and loops quadruples */
typedef struct {
    char *loopLabel;
    char *exitLabel;
} Labels;

/* Used by the parser in handling for loop parameters */
typedef struct {
    char *id;
    char *final_expression_result;
    char *id_type;
    char *final_expression_result_type;
} ForLoopAttributes;

/* Used in the parser when defining a new function */
typedef struct {
    char *name;               // Function name
    char **paramNames;        // Array of parameter names
    char **paramTypes;        // Array of parameter types
    int paramCount;           // Number of parameters
    char *returnType;         // Return type
    char *returnVar;          // Return variable name
} FunctionDef;

#endif // DATA_STRUCTURES_H