#ifndef QUADRUPLE_H
#define QUADRUPLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include <io.h>
#include <unistd.h>
// Define the quadruple structure
typedef struct {
    char operat[10];  // The operation (e.g., "+", "-", "=", "if")
    char operand1[50];  // The first operand
    char operand2[50];  // The second operand (optional)
    char result[50];    // The result of the operation
} Quadruple;

// Define the function definition structure
typedef struct {
    char *name;               // Function name
    char **paramNames;        // Array of parameter names
    char **paramTypes;        // Array of parameter types
    int paramCount;           // Number of parameters
    char *returnType;         // Return type
    char *returnVar;          // Return variable name
} FunctionDef;
// Max number of quadruples
#define MAX_QUADRUPLES 1000

// Global quadruple array and index
extern Quadruple quadruples[MAX_QUADRUPLES];
extern int quadIndex;
extern int tempCounter;
// Function declarations
char *newTemp();
SymbolTableEntry *addQuadruple(const char *operat, SymbolTableEntry *operand1, SymbolTableEntry *operand2);
void printQuadruples();
void addQuadrupleLabel(SymbolTableEntry *condition , char * loopLabel , char* exitLabel, bool beforeSomeCode);
void addQuadrupleFunction(FunctionDef *functionDef , bool beforeSomeCode);
void unmatchedIfQuadruple(SymbolTableEntry *condition , char * loopLabel , char* exitLabel, bool beforeSomeCode);
void matchedIfQuadruple(char* exitLabel, bool beforeSomeCode);
void switchcaseQuadruple(SymbolTableEntry *condition , char * nextLabel ,char* endLabel, bool beforeSomeCode, bool isEnd);
void writeQuadrupleToFile(int i) ;
void writeCommandToFile(char *command) ;
void insertCommandBeforeEnd(const char *command);
void printFileContents(const char *filename);
#endif // QUADRUPLE_H
