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
char* newLabel() {
    static int labelCounter = 0; // Counter to ensure uniqueness
    char* label = (char*)malloc(20 * sizeof(char)); // Allocate memory for the label
    if (!label) {
        fprintf(stderr, "Memory allocation failed for newLabel.\n");
        exit(1);
    }
    snprintf(label, 20, "L%d", labelCounter++); // Create label in the format L0, L1, L2, ...
    return label;
}

void enterScope() {
    Scope *newScope = (Scope *)malloc(sizeof(Scope));
    newScope->symbols = NULL;
    newScope->parent = currentScope;
    currentScope = newScope;
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
    // printf("/////// is init %d\n", entry->isInitialized);
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
//write symbol table to file 
// void displaySymbolTable() {
//     Scope *scope = currentScope;
//     while (scope) {
//         SymbolTableEntry *entry = scope->symbols;
//         while (entry) {
//             printf("Symbol: %s, Type: %s, Initialized: %d, Value: %f\n", 
//                    entry->name, entry->type, entry->isInitialized, entry->value);
//             entry = entry->next;
//         }
//         scope = scope->parent;
//     }
// }
void writeSymbolTableOfCurrentScopeToFile()
{
    FILE *file = fopen("symbol_table.txt", "a");
    if (!file) {
        fprintf(stderr, "Error: Could not open file for writing.\n");
        return;
    }
    SymbolTableEntry *entry = currentScope->symbols;
    while (entry) {
        fprintf(file, "Symbol: %s, Type: %s, Initialized: %d, Value: %f\n", 
               entry->name, entry->type, entry->isInitialized, entry->value);
        entry = entry->next;
    }
    fclose(file);
}

void exitScope() {
    Scope *oldScope = currentScope;
    writeSymbolTableOfCurrentScopeToFile();
    currentScope = currentScope->parent;
    free(oldScope);
}

// void writeSymbolTableToFile(){
//     FILE *file = fopen("symbol_table.txt", "w");
//     if (!file) {
//         fprintf(stderr, "Error: Could not open file for writing.\n");
//         return;
//     }
//     Scope *scope = currentScope;
//     int scopeNumber = 0;
//     while (scope) {
//         SymbolTableEntry *entry = scope->symbols;
//         fprintf(file, "Scope %d\n", scopeNumber);
//         while (entry) {
//             fprintf(file, "Symbol: %s, Type: %s, Initialized: %d, Value: %f\n", 
//                    entry->name, entry->type, entry->isInitialized, entry->value);
//             entry = entry->next;
//         }
//         scope = scope->parent;
//         scopeNumber++;
//     }
// }