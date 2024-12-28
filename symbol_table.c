#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "symbol_table.h"

Scope *currentScope = NULL;  // Pointer to the current (innermost) scope

// Enter a new scope
void enterScope() {
    Scope *newScope = (Scope *)malloc(sizeof(Scope));
    newScope->symbols = NULL;
    newScope->parent = currentScope;
    currentScope = newScope;
}

// Exit the current scope
void exitScope() {
    Scope *oldScope = currentScope;
    currentScope = currentScope->parent;
    free(oldScope);
}

// Add a symbol to the current scope
void addSymbol(char *name, DataType type, bool isConst, Value value) {
    SymbolTableEntry *entry = (SymbolTableEntry *)malloc(sizeof(SymbolTableEntry));
    entry->name = strdup(name);
    entry->type = type;
    entry->isConst = isConst;
    entry->isInitialized = 0;
    entry->isUsed = 0;

    // Set the value based on the type
    switch (type) {
        case INTEGER:
            entry->value.intValue = value.intValue;
            break;
        case FLOAT:
            entry->value.floatValue = value.floatValue;
            break;
        case CHAR:
            entry->value.charValue = value.charValue;
            break;
        case CONST_INTEGER:
            entry->value.intValue = value.intValue;
            break;
        case CONST_FLOAT:
            entry->value.floatValue = value.floatValue;
            break;
        case CONST_CHAR:
            entry->value.charValue = value.charValue;
            break;
        default:
            printf("Unsupported type for symbol: %d\n", type);
            break;
    }

    // Insert the new entry into the symbol table
    entry->next = currentScope->symbols;
    currentScope->symbols = entry;

    printf("Added symbol '%s' with type: %d\n", name, type);
}

// Look up a symbol by name in the current scope and its parent scopes
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

// Update the value of a symbol
int updateSymbolValue(char *name, Value value) {
    SymbolTableEntry *entry = lookupSymbol(name);
    if (entry == NULL) {
        printf("Error: Symbol '%s' not found.\n", name);
        return 0;  // Symbol not found
    }
    if (entry->isConst && entry->isInitialized) {
        printf("Error: Cannot update value of constant symbol '%s'.\n", name);
        return 0;  // Cannot update value of constant symbol
    }

    // Update value based on type
    switch (entry->type) {
        case INTEGER:
            entry->value.intValue = value.intValue;
            break;
        case FLOAT:
            entry->value.floatValue = value.floatValue;
            break;
        case CHAR:
            entry->value.charValue = value.charValue;
            break;
        default:
            printf("Error: Unsupported type for symbol '%s'.\n", name);
            return 0;  // Unsupported type
    }

    entry->isInitialized = 1;  // Mark as initialized
    printf("Updated symbol '%s' with new value: %d\n", name, entry->value.intValue);
    return 1;  // Successfully updated
}

// Check if a symbol is declared in the current scope
bool isSymbolDeclaredInCurrentScope(char *name) {
    SymbolTableEntry *entry = currentScope->symbols;
    while (entry) {
        if (strcmp(entry->name, name) == 0) return true;
        entry = entry->next;
    }
    return false;
}

// Display all symbols in the current scope
void displayScope() {
    SymbolTableEntry *entry = currentScope->symbols;
    while (entry) {
        printf("Symbol: %s, Type: %d, Initialized: %d, Value: ", 
               entry->name, entry->type, entry->isInitialized);
        switch (entry->type) {
            case INTEGER:
                printf("%d\n", entry->value.intValue);
                break;
            case FLOAT:
                printf("%f\n", entry->value.floatValue);
                break;
            case CHAR:
                printf("'%c'\n", entry->value.charValue);
                break;
            default:
                printf("Unknown Type\n");
                break;
        }
        entry = entry->next;
    }
}
