#include "quadruple.h"

// Initialize the quadruple array and index
Quadruple quadruples[MAX_QUADRUPLES];
int quadIndex = 0;

// Function to add a quadruple to the array
SymbolTableEntry *addQuadruple(const char *operat, SymbolTableEntry *operand1, SymbolTableEntry *operand2) {
    // Generate a new temporary variable for the result
    char *result = newTemp();

    printf("Adding quadruple: (%s, %s, %s, %s)\n", operat, operand1->name, operand2->name, result);

    // Ensure operands are copied into local storage, not just pointers
    char operand1_copy[100];
    char operand2_copy[100];
    char result_copy[100];

    strncpy(operand1_copy, operand1->name, sizeof(operand1_copy) - 1);
    operand1_copy[sizeof(operand1_copy) - 1] = '\0'; // Null-terminate

    if (operand2->name) {
        strncpy(operand2_copy, operand2->name, sizeof(operand2_copy) - 1);
        operand2_copy[sizeof(operand2_copy) - 1] = '\0'; // Null-terminate
    } else {
        operand2_copy[0] = '\0'; // Ensure it's empty if not provided
    }

    strncpy(result_copy, result, sizeof(result_copy) - 1);
    result_copy[sizeof(result_copy) - 1] = '\0'; // Null-terminate

    // Store quadruple using copied values
    if (quadIndex >= MAX_QUADRUPLES) {
        fprintf(stderr, "Quadruple storage overflow!\n");
        exit(1);
    }

    strncpy(quadruples[quadIndex].operat, operat, sizeof(quadruples[quadIndex].operat) - 1);
    quadruples[quadIndex].operat[sizeof(quadruples[quadIndex].operat) - 1] = '\0'; // Null-terminate

    strncpy(quadruples[quadIndex].operand1, operand1_copy, sizeof(quadruples[quadIndex].operand1) - 1);
    quadruples[quadIndex].operand1[sizeof(quadruples[quadIndex].operand1) - 1] = '\0'; // Null-terminate

    strncpy(quadruples[quadIndex].operand2, operand2_copy, sizeof(quadruples[quadIndex].operand2) - 1);
    quadruples[quadIndex].operand2[sizeof(quadruples[quadIndex].operand2) - 1] = '\0'; // Null-terminate

    strncpy(quadruples[quadIndex].result, result_copy, sizeof(quadruples[quadIndex].result) - 1);
    quadruples[quadIndex].result[sizeof(quadruples[quadIndex].result) - 1] = '\0'; // Null-terminate
    writeQuadrupleToFile(quadIndex);
    quadIndex++;

    // Determine the type of the result variable (same as the type of operand1)
    char *varType = operand1->type; // Assuming 'type' is a field in SymbolTableEntry

    // Add the result variable to the symbol table with the same type as the operators
    SymbolTableEntry *entry = addSymbol(result, varType, false);

    return entry; // Return the symbol table entry for the result
}

// Function to generate a new label 
void addQuadrupleLabel(SymbolTableEntry *condition , char * loopLabel , char* exitLabel, bool beforeSomeCode) {
    // Store quadruple using copied values
    if (quadIndex >= MAX_QUADRUPLES) {
        fprintf(stderr, "Quadruple storage overflow!\n");
        exit(1);
    }
    /*
    label1: 
    if condition false goto label2
    some code
    goto label1
    label2:
    */
    if (beforeSomeCode) { 
        char * conditionName = condition->name;
        printf("ana get");
        char command[256]; // Adjust the size as needed
        sprintf(command, "%s:\nif %s false goto %s", loopLabel,conditionName, exitLabel);
        writeCommandToFile(command);
    }else{
        char command[256]; // Adjust the size as needed
        sprintf(command, "goto %s\n%s:", loopLabel,exitLabel);
        writeCommandToFile(command);
    }
    quadIndex++;
}
    

// Function to print all generated quadruples 

void printQuadruples() {
    printf("Generated Quadruples:\n");
    for (int i = 0; i < quadIndex; i++) {
        printf("%d: (Operator: %s, Operand1: %s, Operand2: %s, Result: %s)\n", 
               i, 
               quadruples[i].operat,
               quadruples[i].operand1[0] ? quadruples[i].operand1 : "NULL", // Handle empty operand1
               quadruples[i].operand2[0] ? quadruples[i].operand2 : "NULL", // Handle empty operand2
               quadruples[i].result);
    }
}
//function to write one quadruple to a file 
void writeQuadrupleToFile(int i) {
    FILE *file = fopen("quadruples.txt", "a");
    if (file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        exit(1);
    }

    fprintf(file, "%d: (Operator: %s, Operand1: %s, Operand2: %s, Result: %s)\n", 
            i, 
            quadruples[i].operat,
            quadruples[i].operand1[0] ? quadruples[i].operand1 : "NULL", // Handle empty operand1
            quadruples[i].operand2[0] ? quadruples[i].operand2 : "NULL", // Handle empty operand2
            quadruples[i].result);
}
void writeCommandToFile(char *command) {
    FILE *file = fopen("quadruples.txt", "a");
    if (file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        exit(1);
    }

    fprintf(file, "%s\n", command);
}