#ifndef QUADRUPLE_H
#define QUADRUPLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the quadruple structure
typedef struct {
    char operat[10];  // The operation (e.g., "+", "-", "=", "if")
    char operand1[50];  // The first operand
    char operand2[50];  // The second operand (optional)
    char result[50];    // The result of the operation
} Quadruple;

// Max number of quadruples
#define MAX_QUADRUPLES 1000

// Global quadruple array and index
extern Quadruple quadruples[MAX_QUADRUPLES];
extern int quadIndex;
extern int tempCounter;
// Function declarations
char *newTemp();
void addQuadruple(const char *operat, const char *operand1, const char *operand2, const char *result);
void printQuadruples();

#endif // QUADRUPLE_H
