
#include "symbol_table.h"

Scope *currentScope = NULL; 
extern int tempCounter;
Scope *allScopes[1000];     
int scopeCount = 0;    

void enterScope() {
    printf("Entering new scope...\n");
    Scope *newScope = (Scope *)malloc(sizeof(Scope));
    newScope->symbols = NULL;
    newScope->parent = currentScope;
    currentScope = newScope;

    allScopes[scopeCount] = newScope;
    scopeCount++;
    printf("Scope count inside enterScope: %d\n", scopeCount);
}

SymbolTableEntry *addSymbol(char *name, char *type, bool isConst,bool isTempVarOrFunction ) {
    SymbolTableEntry *entry = (SymbolTableEntry *)malloc(sizeof(SymbolTableEntry));
    entry->name = strdup(name);
    entry->type = strdup(type);
    entry->isConst = isConst;
    entry->isInitialized = 0;
    entry->isTempVarOrFunction = isTempVarOrFunction;
    entry->isUsed = 0;
    entry->value = 0.0;  
    entry->next = currentScope->symbols;
    currentScope->symbols = entry;

    printf("Added symbol '%s' with type: %s isConst = %i\n", name, type, isConst);
    return entry;
}

SymbolTableEntry *lookupSymbol(char *name) {
    Scope *scope = currentScope;
    while (scope) {
        SymbolTableEntry *entry = scope->symbols;
        while (entry) {
            if (strcmp(entry->name, name) == 0) return entry;
            entry = entry->next;
        }

        scope = scope->parent;  
    }
    return NULL;                
}

bool isSymbolDeclaredInCurrentScope(char *name) {
    SymbolTableEntry *entry = currentScope->symbols;
    while (entry) {
        if (strcmp(entry->name, name) == 0) return true;
        entry = entry->next;
    }
    return false;
}

int updateSymbolValue(char *name, float value) {
    
    SymbolTableEntry *entry = lookupSymbol(name);
    if (entry == NULL) {
        printf("Error: Symbol '%s' not found.\n", name);
        return 0; 
    }
    if (entry->isConst && entry->isInitialized) {
        printf("Error: Cannot update value of constant symbol '%s'.\n", name);
        return 0; 
    }
    entry->value = value;      
    entry->isInitialized = 1;  
    printf("Updated symbol '%s' with value: %f\n", name, value);
    return 1;  
}
void writeSymbolTableOfAllScopesToFile()
{
    FILE *file = fopen("output_files/symbol_table.txt", "w");
    if (!file) {
        fprintf(stderr, "Error: Could not open file for writing.\n");
        return;
    }

    // Print table header
    fprintf(file, "+-------+----------------+--------+-------------+---------+------------+\n");
    fprintf(file, "| Scope | Symbol         | Type   | Initialized | Value   | Is Temp    |\n");
    fprintf(file, "+-------+----------------+--------+-------------+---------+------------+\n");

    for (int i = 0; i < scopeCount; i++) {
        SymbolTableEntry *entry = allScopes[i]->symbols;
        while (entry) {
            fprintf(file, "| %-5d | %-14s | %-6s | %-11d | %-7.2f | %-10d |\n",
                i,
                entry->name, entry->type, entry->isInitialized, entry->value, entry->isTempVarOrFunction);
            entry = entry->next;
        }
    }

    // Print table footer
    fprintf(file, "+-------+----------------+--------+-------------+---------+------------+\n");

    fclose(file);
}

void exitScope() {
    Scope *oldScope = currentScope;
    currentScope = currentScope->parent;
  
}
void checkUnusedVariables() {
    FILE *file = fopen("output_files/semantics.txt", "a");
    if (!file) {
        fprintf(stderr, "Error: Could not open file for writing.\n");
        return;
    }
    printf("Checking for unused variables...\n");
    printf("scope count: %d\n", scopeCount);
    for (int i = 0; i < scopeCount; i++) {
        SymbolTableEntry *entry = allScopes[i]->symbols;
        while (entry) {
            if (!entry->isTempVarOrFunction&&!entry->isUsed) {
               fprintf(file, "Unused variable: %s in scope %d\n", entry->name, i);
                printf("Unused variable: %s in scope %d\n", entry->name, i);
            }
            entry = entry->next;
        }
    }

    fclose(file);
}