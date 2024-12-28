#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symbol_table.h"

Scope *currentScope = NULL;  // Pointer to the current (innermost) scope
int tempCounter = 0;

char *newTemp() {
    static char tempName[16]   ;    
    snprintf(tempName, sizeof(tempName), "t%d", tempCounter++);
    printf("Creating new temp: %s\n", tempName);
    return tempName;
}

void enterScope() {
    Scope *newScope = (Scope *)malloc(sizeof(Scope));
    newScope->symbols = NULL;
    newScope->parent = currentScope;
    currentScope = newScope;
}

void exitScope() {
    Scope *oldScope = currentScope;
    currentScope = currentScope->parent;
    free(oldScope);
}


SymbolTableEntry *addSymbol(char *name, char *type, bool isConst) {
    SymbolTableEntry *entry = (SymbolTableEntry *)malloc(sizeof(SymbolTableEntry));
    entry->name = strdup(name);
    entry->type = strdup(type);
    entry->isConst = isConst;
    entry->isInitialized = 0;
    entry->isUsed = 0;
    entry->value = 0.0;  // Initialize value to 0
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

        scope = scope->parent;  // Go to parent scope
    }
    return NULL;  // Symbol not found
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
        return 0;  // Symbol not found
    }
    printf("/////// is init %d\n", entry->isInitialized);
    if (entry->isConst && entry->isInitialized) {
        printf("Error: Cannot update value of constant symbol '%s'.\n", name);
        return 0;  // Cannot update value of constant symbol
    }
    entry->value = value;  // Update value
    entry->isInitialized = 1;  // Mark as initialized
    printf("Updated symbol '%s' with value: %f\n", name, value);
    return 1;  // Successfully updated
}

void displayScope() {
    SymbolTableEntry *entry = currentScope->symbols;
    while (entry) {
        printf("Symbol: %s, Type: %s, Initialized: %d, Value: %f\n", 
               entry->name, entry->type, entry->isInitialized, entry->value);
        entry = entry->next;
    }
}
