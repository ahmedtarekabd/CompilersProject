#include "quadruple.h"
Quadruple quadruples[MAX_QUADRUPLES];
int quadIndex = 0;

/*Used For writing All Mathematical , Logical , Rel operators*/
SymbolTableEntry *addQuadruple(const char *operat, SymbolTableEntry *operand1, SymbolTableEntry *operand2) {
    checkQuadrupleStorageOverflow();

    char *operand1_name = operand1->name;
    char *operand1_type = operand1->type;
    char *operand2_name = operand2 ? operand2->name : NULL;
    char *operand2_type = operand2 ? operand2->type : NULL;

    // Generate a new temporary variable for the result
    char *result = newTemp();

    // Ensure operands are copied into local storage, not just pointers
    char operand1_copy[100];
    char operand2_copy[100] = {0}; // Initialize to empty string
    char result_copy[100];

    copyString(operand1_copy, operand1_name, sizeof(operand1_copy));
    if (operand2) {
        copyString(operand2_copy, operand2_name, sizeof(operand2_copy));
    }
    copyString(result_copy, result, sizeof(result_copy));

    // Store quadruple using copied values
    copyString(quadruples[quadIndex].operat, operat, sizeof(quadruples[quadIndex].operat));
    copyString(quadruples[quadIndex].operand1, operand1_copy, sizeof(quadruples[quadIndex].operand1));
    copyString(quadruples[quadIndex].operand2, operand2_copy, sizeof(quadruples[quadIndex].operand2));
    copyString(quadruples[quadIndex].result, result_copy, sizeof(quadruples[quadIndex].result));

    writeQuadrupleToFile(quadIndex);
    quadIndex++;

    const char *varType = operand2 ? determineVarType(operand1_type, operand2_type, operand1_name, operand2_name) : operand1_type;

    SymbolTableEntry *entry = addSymbol(result, (char *)varType, false, true); // Cast const char * to char *
    return entry; // Return the symbol table entry for the result
}


/*converting for loops , while loops , Repeat until into  quadruples*/
void addQuadrupleLabel(SymbolTableEntry *condition, char *loopLabel, char *exitLabel, bool beforeSomeCode)
{
  
  checkQuadrupleStorageOverflow();

    if(beforeSomeCode && !exitLabel && !condition){
        char command[256]; 
        sprintf(command, "%s:", loopLabel);
        writeCommandToFile(command);
        return;
    }
    if (exitLabel == NULL) /* Repeat until loop */
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
        char command[256]; 
        if (beforeSomeCode)
            sprintf(command, "%s:", loopLabel);
        else
            sprintf(command, "if %s goto %s", condition->name, loopLabel);

        writeCommandToFile(command);
        return;
    }
    char command[256]; 
    if (beforeSomeCode)
    {
        char *conditionName = condition->name;
        sprintf(command, "if %s false goto %s", conditionName, exitLabel);
    }
    else
        sprintf(command, "goto %s\n%s:", loopLabel, exitLabel);
    
    writeCommandToFile(command);
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
    char command[256]; 
    if (beforeSomeCode)   {
        char *conditionName = condition->name;
        sprintf(command, "if %s goto %s\ngoto %s \n%s:", conditionName, loopLabel, exitLabel, loopLabel);
    }
    else
        sprintf(command, "%s:", exitLabel);

    writeCommandToFile(command);
    quadIndex++;
}
void matchedIfQuadruple(char *exitLabel, bool beforeSomeCode)
{
    if (beforeSomeCode)
    {
        char command[256]; 
        sprintf(command, "goto %s", exitLabel);
        // Write the command in the line before the end of the file
        insertCommandBeforeEnd(command);
        // writeCommandToFile(command);
    }
    else
    {
        char command[256]; 
        sprintf(command, "%s:", exitLabel);
        writeCommandToFile(command);
    }
    quadIndex++;
}

void switchcaseQuadruple(SymbolTableEntry *condition, char *nextLabel, char *endLabel, bool beforeSomeCode, bool isEnd)
{    char command[256]; 
    if (isEnd)
        sprintf(command, " %s:", endLabel);
    else
    {
        if (beforeSomeCode)
        {
            char *conditionName = condition->name;
            sprintf(command, "if %s false goto %s", conditionName, nextLabel);
        }
        else
            sprintf(command, "goto %s\n%s:", endLabel, nextLabel);
        
    }
    writeCommandToFile(command);
    quadIndex++;
}
void addQuadrupleFunction(FunctionDef *functionDef, bool beforeSomeCode)
{
    checkQuadrupleStorageOverflow();
    char command[256]; 
    if (beforeSomeCode)
    {
        sprintf(command, "%s proc %s ", functionDef->returnType, functionDef->name);
        for (int i = 0; i < functionDef->paramCount; i++)
        {
            char param[100]; 
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
    checkQuadrupleStorageOverflow();
    char command[256]; 
    bool isVoid = strncmp(function->type, "void", 4) == 0;

    sprintf(command, "call %s", function->name);
    for (int i = 0; i < currentFunctionParamsCount; i++)
    {
        char param[100]; 
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
    FILE *file = fopen("output_files/quadruples.txt", "a");
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
    FILE *file = fopen("output_files/quadruples.txt", "a");
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
    FILE *file = fopen("output_files/quadruples.txt", "r");
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
    file = fopen("output_files/quadruples.txt", "w");
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

void handleTypeConversion(const char *fromType, const char *toType, const char *varName)
{
    char message[256];
    snprintf(message, sizeof(message), "Implicit conversion from %s to %s for variable: %s", fromType, toType, varName);
    semanticError(message);
}
const char* determineVarType(const char *operand1_type, const char *operand2_type, const char *operand1_name, const char *operand2_name) {
    if (strcmp(operand1_type, operand2_type) == 0) {
        return operand1_type;
    } else if (strcmp(operand1_type, "int") == 0 && strcmp(operand2_type, "float") == 0) {
        handleTypeConversion("int", "float", operand1_name);
        return "float";
    } else if (strcmp(operand1_type, "float") == 0 && strcmp(operand2_type, "int") == 0) {
        handleTypeConversion("int", "float", operand2_name);
        return "float";
    } else if (strcmp(operand1_type, "int") == 0 && strcmp(operand2_type, "char") == 0) {
        handleTypeConversion("int", "char", operand1_name);
        return "char";
    } else if (strcmp(operand1_type, "char") == 0 && strcmp(operand2_type, "int") == 0) {
        handleTypeConversion("int", "char", operand2_name);
        return "char";
    } else if (strcmp(operand1_type, "char") == 0 && strcmp(operand2_type, "string") == 0) {
        handleTypeConversion("char", "string", operand1_name);
        return "string";
    } else if (strcmp(operand1_type, "string") == 0 && strcmp(operand2_type, "char") == 0) {
        handleTypeConversion("char", "string", operand2_name);
        return "string";
    } else {
        char message[256];
        snprintf(message, sizeof(message), "Invalid type conversion between %s and %s", operand1_type, operand2_type);
        semanticError(message);
        return NULL;
    }
}
void copyString(char *dest, const char *src, size_t size) {
    strncpy(dest, src, size - 1);
    dest[size - 1] = '\0'; // Null-terminate
}
void checkQuadrupleStorageOverflow() {
    if (quadIndex >= MAX_QUADRUPLES) {
        fprintf(stderr, "Quadruple storage overflow!\n");
        exit(1);
    }
}