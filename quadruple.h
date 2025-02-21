#ifndef QUADRUPLE_H
#define QUADRUPLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include <unistd.h>
#include "utils/helper_functions.h"
extern int yylineno;
// Define the quadruple structure
typedef struct
{
    char operat[10];   // The operation (e.g., "+", "-", "=", "if")
    char operand1[50]; // The first operand
    char operand2[50]; // The second operand (optional)
    char result[50];   // The result of the operation
} Quadruple;
// Max number of quadruples
#define MAX_QUADRUPLES 1000

// Global quadruple array and index
extern Quadruple quadruples[MAX_QUADRUPLES];
extern int quadIndex;
extern int tempCounter;
// Function declarations
SymbolTableEntry *addQuadruple(const char *operat, SymbolTableEntry *operand1, SymbolTableEntry *operand2);
SymbolTableEntry *addQuadrupleFunctionCall(SymbolTableEntry *function_name, SymbolTableEntry **currentFunctionParams, int currentFunctionParamsCount);
void addQuadrupleFunction(FunctionDef *functionDef, bool beforeSomeCode);
void addQuadrupleLabel(SymbolTableEntry *condition, char *loopLabel, char *exitLabel, bool beforeSomeCode);
void unmatchedIfQuadruple(SymbolTableEntry *condition, char *loopLabel, char *exitLabel, bool beforeSomeCode);
void matchedIfQuadruple(char *exitLabel, bool beforeSomeCode);
void switchcaseQuadruple(SymbolTableEntry *condition, char *nextLabel, char *endLabel, bool beforeSomeCode, bool isEnd);
void printQuadruples();
void writeQuadrupleToFile(int i);
void writeCommandToFile(char *command);
void insertCommandBeforeEnd(const char *command);
void printFileContents(const char *filename);
void handleTypeConversion(const char *fromType, const char *toType, const char *varName);
void semanticError(const char *s);
void copyString(char *dest, const char *src, size_t size);
void checkQuadrupleStorageOverflow();
const char *determineVarType(const char *operand1_type, const char *operand2_type, const char *operand1_name, const char *operand2_name);

#endif // QUADRUPLE_H
