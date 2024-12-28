#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdbool.h>

// typedef enum {
//     TYPE_INT,
//     TYPE_FLOAT,
//     TYPE_CHAR,
//     TYPE_CONST_INT,
//     TYPE_CONST_FLOAT,
//     TYPE_CONST_CHAR,
//     TYPE_UNKNOWN
// } DataType;

typedef struct SymbolTable {
    char *name;               // Variable or function name
    char *type;               // Data type (e.g., int, float)
    bool isConst;             // 1 if the symbol is a constant, 0 otherwise
    int isInitialized;        // 1 if initialized, 0 otherwise
    int isUsed;               // 1 if used, 0 otherwise
    float value;              // Store variable's value (assuming the type is numeric)
    struct SymbolTable *next; // Pointer to next symbol in this table
} SymbolTableEntry;

typedef struct Scope {
    SymbolTableEntry *symbols;  // Linked list of symbols
    struct Scope *parent;       // Pointer to the parent scope
} Scope;

extern Scope *currentScope;  // Pointer to the current (innermost) scope

void enterScope();
void exitScope();
char *newTemp();
char *newLabel();
SymbolTableEntry *addSymbol(char *name, char *type, bool isConst);
SymbolTableEntry *lookupSymbol(char *name);
int updateSymbolValue(char *name, float value);
bool isSymbolDeclaredInCurrentScope(char *name);
void displayScope();

#endif // SYMBOL_TABLE_H
