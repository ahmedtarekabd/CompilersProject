#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_CHAR,
    TYPE_CONST_INT,
    TYPE_CONST_FLOAT,
    TYPE_CONST_CHAR,
    TYPE_UNKNOWN
} DataType;

typedef struct SymbolTable {
    char *name;               // Variable or function name
    char *type;               // Data type (e.g., int, float)
    int isInitialized;        // 1 if initialized, 0 otherwise
    int isUsed;               // 1 if used, 0 otherwise
    float value;              // Store variable's value (assuming the type is numeric)
    struct SymbolTable *next; // Pointer to next symbol in this table
} SymbolTableEntry;

typedef struct Scope {
    SymbolTableEntry *symbols;  // Linked list of symbols
    struct Scope *parent;       // Pointer to the parent scope
} Scope;

Scope *currentScope = NULL;  // Pointer to the current (innermost) scope

// Function to enter a new scope
void enterScope() {
    Scope *newScope = (Scope *)malloc(sizeof(Scope));
    newScope->symbols = NULL;
    newScope->parent = currentScope;
    currentScope = newScope;
}

// Function to exit the current scope
void exitScope() {
    Scope *oldScope = currentScope;
    currentScope = currentScope->parent;
    free(oldScope);
}

// Function to add a symbol to the current scope
void addSymbol(char *name, char *type) {
    SymbolTableEntry *entry = (SymbolTableEntry *)malloc(sizeof(SymbolTableEntry));
    entry->name = strdup(name);
    entry->type = strdup(type);
    entry->isInitialized = 0;
    entry->isUsed = 0;
    entry->value = 0.0;  // Initialize value to 0
    entry->next = currentScope->symbols;
    currentScope->symbols = entry;
}

// Function to look up a symbol in the current scope and all parent scopes
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

// Function to update a symbol's value in the symbol table
int updateSymbolValue(char *name, float value) {
    SymbolTableEntry *entry = lookupSymbol(name);
    if (entry == NULL) {
        printf("Error: Symbol '%s' not found.\n", name);
        return 0;  // Symbol not found
    }
    entry->value = value;  // Update value
    entry->isInitialized = 1;  // Mark as initialized
    printf("Updated symbol '%s' with value: %f\n", name, value);
    return 1;  // Successfully updated
}

// Function to display all symbols in the current scope
void displayScope() {
    SymbolTableEntry *entry = currentScope->symbols;
    while (entry) {
        printf("Symbol: %s, Type: %s, Initialized: %d, Value: %f\n", 
               entry->name, entry->type, entry->isInitialized, entry->value);
        entry = entry->next;
    }
}