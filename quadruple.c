#include "quadruple.h"

// Initialize the quadruple array and index
Quadruple quadruples[MAX_QUADRUPLES];
int quadIndex = 0;
// Function to add a quadruple to the array
SymbolTableEntry *addQuadruple(const char *operat, SymbolTableEntry *operand1, SymbolTableEntry *operand2)
{    char * operand1_name = operand1->name;
    char * operand1_type = operand1->type;
    char * operand2_name = operand2->name;
    char * operand2_type = operand2->type;
    // Generate a new temporary variable for the result
    char *result = newTemp();
    // printf("Adding quadruple: (%s, %s, %s, %s)\n", operat, operand1->name, operand2->name, result);
    
    // Ensure operands are copied into local storage, not just pointers
    char operand1_copy[100];
    char operand2_copy[100];
    char result_copy[100];
    strncpy(operand1_copy, operand1->name, sizeof(operand1_copy) - 1);
    operand1_copy[sizeof(operand1_copy) - 1] = '\0'; // Null-terminate
    if (operand2)
    {

        strncpy(operand2_copy, operand2->name, sizeof(operand2_copy) - 1);
        operand2_copy[sizeof(operand2_copy) - 1] = '\0'; // Null-terminate
    }
    else
    {
        operand2_copy[0] = '\0'; // Ensure it's empty if not provided
    }


    strncpy(result_copy, result, sizeof(result_copy) - 1);
    result_copy[sizeof(result_copy) - 1] = '\0'; // Null-terminate

    // Store quadruple using copied values
    if (quadIndex >= MAX_QUADRUPLES)
    {
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
    char *varType;
    char *operand_name;
    char *message;
    // CHECK FOR IMPILICIT TYPE CONVERSION
    printf("adding quadruple\n");
    printf("operand1 name: %s\n", operand1_name);
    printf("operand1 type: %s\n", operand1_type);
    printf("operand2 name: %s\n", operand2_name);
    printf("operand2 type: %s\n", operand2_type);
    
    if (operand2)
    if (strcmp(operand1_type, operand2_type) == 0)
    {   
        varType = operand1_type;
    }
    else
    {
            if (strcmp(operand1_type, "int") == 0 && strcmp(operand2_type, "float") == 0)
            {
   
                varType = "float";
                handleTypeConversion("int", "float", operand1_name);
            }
            else if (strcmp(operand1_type, "float") == 0 && strcmp(operand2_type, "int") == 0)
            {
                varType = "float";
                handleTypeConversion("int", "float", operand2_name);
            }
            else if (strcmp(operand1_type, "int") == 0 && strcmp(operand2_type, "char") == 0)
            {
                varType = "char";
                handleTypeConversion("int", "char", operand1_name);
            }
            else if (strcmp(operand1_type, "char") == 0 && strcmp(operand2_type, "int") == 0)
            {
                varType = "char";
                handleTypeConversion("int", "char", operand2_name);
            }
            else if (strcmp(operand1_type, "char") == 0 && strcmp(operand2_type, "string") == 0)
            {
                varType = "string";
                handleTypeConversion("char", "string", operand1_name);
            }
            else if (strcmp(operand1_type, "string") == 0 && strcmp(operand2_type, "char") == 0)
            {
                varType = "string";
                handleTypeConversion("char", "string", operand2_name);
            }
            else
            {
                char message[256]; // Adjust the size as needed
                sprintf(message, "Invalid type conversion between %s and %s", operand1_type, operand2_type);
                semanticError(message);
            }
    }
    else
    {
        varType = operand1_type;
    }
    SymbolTableEntry *entry = addSymbol(result, varType, false, true);
    return entry; // Return the symbol table entry for the result
}

// Function to generate a new label
void addQuadrupleLabel(SymbolTableEntry *condition, char *loopLabel, char *exitLabel, bool beforeSomeCode)
{
    // Store quadruple using copied values
    if (quadIndex >= MAX_QUADRUPLES)
    {
        fprintf(stderr, "Quadruple storage overflow!\n");
        exit(1);
    }
    if (exitLabel == NULL)
    {
        /*
        repeat {
            some code
        } until (i<6)
        ---->
        label1:
        some code
        if i<6 goto label1
        */
        if (beforeSomeCode)
        {
            char command[256]; // Adjust the size as needed
            // print loop label
            sprintf(command, "%s:", loopLabel);
            writeCommandToFile(command);
        }
        else
        {
            char command[256]; // Adjust the size as needed
            sprintf(command, "if %s goto %s", condition->name, loopLabel);
            writeCommandToFile(command);
        }
        return;
    }
    /*
    label1:
    if condition false goto label2
    some code
    goto label1
    label2:
    */
    if (beforeSomeCode)
    {
        char *conditionName = condition->name;

        char command[256]; // Adjust the size as needed
        sprintf(command, "%s:\nif %s false goto %s", loopLabel, conditionName, exitLabel);
        writeCommandToFile(command);
    }
    else
    {

        char command[256]; // Adjust the size as needed
        sprintf(command, "goto %s\n%s:", loopLabel, exitLabel);
        writeCommandToFile(command);
    }
    quadIndex++;
}
void unmatchedIfQuadruple(SymbolTableEntry *condition, char *loopLabel, char *exitLabel, bool beforeSomeCode)
{
    /*
    if (i>=6) {
        some code
    }
    ---->
    if i>=6 goto label1
    goto label2
    label1:
    some code
    label2:
    */
    if (beforeSomeCode)
    {
        char *conditionName = condition->name;
        char command[256]; // Adjust the size as needed
        sprintf(command, "if %s goto %s\ngoto %s \n%s:", conditionName, loopLabel, exitLabel, loopLabel);
        writeCommandToFile(command);
    }
    else
    {
        char command[256]; // Adjust the size as needed
        sprintf(command, "%s:", exitLabel);
        writeCommandToFile(command);
    }
    quadIndex++;
}
void matchedIfQuadruple(char *exitLabel, bool beforeSomeCode)
{
    if (beforeSomeCode)
    {
        char command[256]; // Adjust the size as needed
        sprintf(command, "goto %s", exitLabel);
        // Write the command in the line before the end of the file
        insertCommandBeforeEnd(command);
        // writeCommandToFile(command);
    }
    else
    {
        char command[256]; // Adjust the size as needed
        sprintf(command, "%s:", exitLabel);
        writeCommandToFile(command);
    }
    quadIndex++;
}

void switchcaseQuadruple(SymbolTableEntry *condition, char *nextLabel, char *endLabel, bool beforeSomeCode, bool isEnd)
{
    if (isEnd)
    {
        // endLabel:
        char command[256]; // Adjust the size as needed
        sprintf(command, " %s:", endLabel);
        writeCommandToFile(command);
    }
    else
    {
        if (beforeSomeCode)
        {

            // if i!=1 goto label2
            char *conditionName = condition->name;
            char command[256]; // Adjust the size as needed
            sprintf(command, "if %s false goto %s", conditionName, nextLabel);
            writeCommandToFile(command);
        }
        else
        {
            // goto endLabel
            // label2;
            char command[256]; // Adjust the size as needed
            sprintf(command, "goto %s\n%s:", endLabel, nextLabel);
            writeCommandToFile(command);
        }
    }
    quadIndex++;
}
void addQuadrupleFunction(FunctionDef *functionDef, bool beforeSomeCode)
{
    // Store quadruple using copied values
    if (quadIndex >= MAX_QUADRUPLES)
    {
        fprintf(stderr, "Quadruple storage overflow!\n");
        exit(1);
    }
    char command[256]; // Adjust the size as needed
    if (beforeSomeCode)
    {
        sprintf(command, "%s proc %s ", functionDef->returnType, functionDef->name);
        for (int i = 0; i < functionDef->paramCount; i++)
        {
            char param[100]; // Adjust the size as needed
            sprintf(param, "%s %s", functionDef->paramTypes[i], functionDef->paramNames[i]);
            strcat(command, param);
            if (i < functionDef->paramCount - 1)
            {
                strcat(command, ", ");
            }
        }
        writeCommandToFile(command);
    }
    else
    {
        if (strncmp(functionDef->returnType, "void", 4) != 0)
        {
            sprintf(command, "return %s\n", functionDef->returnVar);
        }
        else
        {
            sprintf(command, "return");
        }
        writeCommandToFile(command);
    }

    quadIndex++;
}
SymbolTableEntry *addQuadrupleFunctionCall(SymbolTableEntry *function, SymbolTableEntry **currentFunctionParams, int currentFunctionParamsCount)
{
    char *result = newTemp();
    // Store quadruple using copied values
    if (quadIndex >= MAX_QUADRUPLES)
    {
        fprintf(stderr, "Quadruple storage overflow!\n");
        exit(1);
    }
    char command[256]; // Adjust the size as needed
    bool isVoid = strncmp(function->type, "void", 4) == 0;

    sprintf(command, "call %s", function->name);
    for (int i = 0; i < currentFunctionParamsCount; i++)
    {
        char param[100]; // Adjust the size as needed
        sprintf(param, " %s", currentFunctionParams[i]->name);
        strcat(command, param);
        if (i < currentFunctionParamsCount - 1)
        {
            strcat(command, ",");
        }
    }
    if (!isVoid)
    {
        strcat(command, " :=");
        strcat(command, result);
    }
    writeCommandToFile(command);
    quadIndex++;
    // henaaa
    SymbolTableEntry *entry = addSymbol(result, function->type, false, true);
}

void printQuadruples()
{
    printf("Generated Quadruples:\n");
    for (int i = 0; i < quadIndex; i++)
    {
        printf("%d: (Operator: %s, Operand1: %s, Operand2: %s, Result: %s)\n",
               i,
               quadruples[i].operat,
               quadruples[i].operand1[0] ? quadruples[i].operand1 : "NULL", // Handle empty operand1
               quadruples[i].operand2[0] ? quadruples[i].operand2 : "NULL", // Handle empty operand2
               quadruples[i].result);
    }
}
// function to write one quadruple to a file
void writeQuadrupleToFile(int i)
{
    FILE *file = fopen("quadruples.txt", "a");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file!\n");
        exit(1);
    }

    fprintf(file, "%s  %s  %s :=%s\n",
            quadruples[i].operat,
            quadruples[i].operand1[0] ? quadruples[i].operand1 : "", // Handle empty operand1
            quadruples[i].operand2[0] ? quadruples[i].operand2 : "", // Handle empty operand2
            quadruples[i].result);
    fclose(file);
}
void writeCommandToFile(char *command)
{
    FILE *file = fopen("quadruples.txt", "a");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file!\n");
        exit(1);
    }
    fprintf(file, "%s\n", command);
    fclose(file);
}
void insertCommandBeforeEnd(const char *command)
{
    FILE *file = fopen("quadruples.txt", "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file!\n");
        exit(1);
    }
    char line[256];
    char *lines[1000];
    int i = 0;
    while (fgets(line, sizeof(line), file))
    {
        lines[i] = strdup(line);
        i++;
    }
    fclose(file);
    file = fopen("quadruples.txt", "w");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file!\n");
        exit(1);
    }
    for (int j = 0; j < i - 1; j++)
    {
        fprintf(file, "%s", lines[j]);
    }
    fprintf(file, "%s\n", command);
    fprintf(file, "%s", lines[i - 1]);
    fclose(file);
}
void printFileContents(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file %s for reading!\n", filename);
        exit(1);
    }
    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line); // Print each line to the console
    }
    fclose(file);
}
void semanticError(const char *s)
{
    FILE *errorFile = fopen("semantic_err.txt", "a");
    if (errorFile == NULL)
    {
        fprintf(stderr, "Error opening semantic_err.txt for writing!\n");
        return;
    }
    fprintf(errorFile, "Semantic error: %s at line %d\n", s, yylineno);
    fclose(errorFile);
    fprintf(stderr, "Semantic error: %s at line %d\n", s, yylineno);
}
void handleTypeConversion(const char *fromType, const char *toType, const char *varName)
{
    char message[256];
    snprintf(message, sizeof(message), "Implicit conversion from %s to %s for variable: %s", fromType, toType, varName);
    semanticError(message);
}