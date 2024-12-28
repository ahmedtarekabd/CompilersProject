#ifndef QUADRUPLE_H
#define QUADRUPLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

// Define the quadruple structure
typedef struct {
    char operat[10];  // The operation (e.g., "+", "-", "=", "if")
    char operand1[50];  // The first operand
    char operand2[50];  // The second operand (optional)
    char result[50];    // The result of the operation
} Quadruple;

typedef struct {
    char *loopLabel;
    char *exitLabel;
} Labels;
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
void writeQuadrupleToFile(int i) ;
void writeCommandToFile(char *command) ;
#endif // QUADRUPLE_H
