#include "quadruple.h"

// Initialize the quadruple array and index
Quadruple quadruples[MAX_QUADRUPLES];
int quadIndex = 0;

int tempCounter = 0;

char *newTemp() {
    static char tempName[16]   ;    
    snprintf(tempName, sizeof(tempName), "t%d", tempCounter++);
    printf("Creating new temp: %s\n", tempName);
    return tempName;
}

// Function to add a quadruple to the array
void addQuadruple(const char *operat, const char *operand1, const char *operand2, const char *result) {
    printf("Adding quadruple: (%s, %s, %s, %s)\n", operat, operand1, operand2, result);

    // Ensure operands are copied into local storage, not just pointers
    char operand1_copy[100];
    char operand2_copy[100];
    char result_copy[100];

    strncpy(operand1_copy, operand1, sizeof(operand1_copy) - 1);
    strncpy(operand2_copy, operand2, sizeof(operand2_copy) - 1);
    strncpy(result_copy, result, sizeof(result_copy) - 1);

    // Store quadruple using copied values
    if (quadIndex >= MAX_QUADRUPLES) {
        fprintf(stderr, "Quadruple storage overflow!\n");
        exit(1);
    }

    strncpy(quadruples[quadIndex].operat, operat, sizeof(quadruples[quadIndex].operat) - 1);
    strncpy(quadruples[quadIndex].operand1, operand1_copy, sizeof(quadruples[quadIndex].operand1) - 1);
    if (operand2) {
        strncpy(quadruples[quadIndex].operand2, operand2_copy, sizeof(quadruples[quadIndex].operand2) - 1);
    } else {
        quadruples[quadIndex].operand2[0] = '\0'; // Ensure it's empty if not provided
    }
    strncpy(quadruples[quadIndex].result, result_copy, sizeof(quadruples[quadIndex].result) - 1);

    quadIndex++;
}


// Function to print all generated quadruples
void printQuadruples() {
    printf("Generated Quadruples:\n");
    for (int i = 0; i < quadIndex; i++) {
        printf("%d: (%s, %s, %s, %s)\n", i, quadruples[i].operat,
               quadruples[i].operand1, quadruples[i].operand2, quadruples[i].result);
    }
}
