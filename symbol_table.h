#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdbool.h>

// Enum for Data Types
typedef enum {
    INTEGER,
    FLOAT,
    CHAR,
    CONST_INTEGER,
    CONST_FLOAT,
    CONST_CHAR,
    UNKNOWN
} DataType;

// Union to hold different types of values (int, float, char)
typedef union {
    int intValue;
    float floatValue;
    char charValue;
} Value;

// Symbol Table Entry structure
typedef struct SymbolTable {
    char *name;               // Variable or function name
    DataType type;            // Data type (e.g., int, float, char)
    bool isConst;             // 1 if the symbol is a constant, 0 otherwise
    int isInitialized;        // 1 if initialized, 0 otherwise
    int isUsed;               // 1 if used, 0 otherwise
    Value value;              // Store variable's value (supports int, float, char)
    struct SymbolTable *next; // Pointer to next symbol in this table
} SymbolTableEntry;

// Scope structure, used for nested scopes
typedef struct Scope {
    SymbolTableEntry *symbols;  // Linked list of symbols
    struct Scope *parent;       // Pointer to the parent scope
} Scope;

extern Scope *currentScope;  // Pointer to the current (innermost) scope

void enterScope();
void exitScope();
void addSymbol(char *name, DataType type, bool isConst, Value value);
SymbolTableEntry *lookupSymbol(char *name);
int updateSymbolValue(char *name, Value value);
bool isSymbolDeclaredInCurrentScope(char *name);
void displayScope();

#endif // SYMBOL_TABLE_H
