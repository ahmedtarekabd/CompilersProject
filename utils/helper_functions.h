#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include "../symbol_table.h"
#include "data_structures.h"

char *newTemp();
char *newLabel();
Labels *createLabels(int numLabels);
void freeLabels(void *data);
ForLoopAttributes *createForLoopAttributes(const char *id, const char *finalResult, const char *idType, const char *resultType);
void freeForLoopAttributes(void *data);
void clearFile(const char *filename);
void initializeCurrentFunction(FunctionDef **currentFunction, const char *name, const char *returnType);
void semanticError(const char *s);
#endif // HELPER_FUNCTIONS_H