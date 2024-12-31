#include "helper_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylineno;
static int tempCounter = 0;

char *newTemp() {
    static char tempName[16];
    snprintf(tempName, sizeof(tempName), "t%d", tempCounter++);
    return strdup(tempName);
}

char *newLabel() {
    static int labelCounter = 0;
    char *label = (char *)malloc(20 * sizeof(char));
    snprintf(label, 20, "L%d", labelCounter++);
    return label;
}

Labels *createLabels(int numLabels) {
    Labels *labels = (Labels *)malloc(sizeof(Labels));
    if(numLabels == 2)
    {
       
        labels->loopLabel = newLabel();
        labels->exitLabel = newLabel();

    } else if (numLabels == 1)
    {
        labels->loopLabel = newLabel();
        labels->exitLabel = NULL;
    }
    else
    {
        labels->loopLabel = NULL;
        labels->exitLabel = newLabel();
    }
   
    return labels;
}

void freeLabels(void *data) {
    Labels *labels = (Labels *)data;
    free(labels->loopLabel);
    free(labels->exitLabel);
    free(labels);
}

ForLoopAttributes *createForLoopAttributes(const char *id, const char *finalResult, const char *idType, const char *resultType) {
    ForLoopAttributes *attributes = (ForLoopAttributes *)malloc(sizeof(ForLoopAttributes));
    attributes->id = strdup(id);
    attributes->final_expression_result = strdup(finalResult);
    attributes->id_type = strdup(idType);
    attributes->final_expression_result_type = strdup(resultType);
    return attributes;
}

void freeForLoopAttributes(void *data) {
    ForLoopAttributes *attributes = (ForLoopAttributes *)data;
    free(attributes->id);
    free(attributes->final_expression_result);
    free(attributes->id_type);
    free(attributes->final_expression_result_type);
    free(attributes);
}



void clearFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file) {
        fclose(file);
    }
}

void initializeCurrentFunction(FunctionDef **currentFunction, const char *name, const char *returnType) {
    *currentFunction = (FunctionDef *)malloc(sizeof(FunctionDef));
    (*currentFunction)->name = strdup(name);
    (*currentFunction)->paramNames = NULL;
    (*currentFunction)->paramTypes = NULL;
    (*currentFunction)->paramCount = 0;
    (*currentFunction)->returnType = strdup(returnType);
    (*currentFunction)->returnVar = NULL;
}
void semanticError(const char *s)
{
    FILE *errorFile = fopen("output_files/semantics.txt", "a");
    if (errorFile == NULL)
    {
        fprintf(stderr, "Error opening output_files/semantics.txt for writing!\n");
        return;
    }
    fprintf(errorFile, "Semantic error: %s at line %d\n", s, yylineno);
    fclose(errorFile);
    fprintf(stderr, "Semantic error: %s at line %d\n", s, yylineno);
}