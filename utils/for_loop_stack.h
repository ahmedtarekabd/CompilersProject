#ifndef FOR_LOOP_STACK_H
#define FOR_LOOP_STACK_H

#include <stdlib.h>

typedef struct {
    char * id;
    char * final_expression_result;
    char * id_type;
    char * final_expression_result_type;
} ForLoopAttributes;
typedef struct forLoopStackNode {
    ForLoopAttributes *forLoopAttributes;
    struct forLoopStackNode *next;
} forLoopStackNode;

typedef struct {
    forLoopStackNode *top;
} ForLoopStack;

ForLoopStack* createForLoopStack();
void pushForLoopStack(ForLoopStack **stack, ForLoopAttributes *forLoopAttributes);
ForLoopAttributes* popForLoopStack(ForLoopStack *stack);
ForLoopAttributes* peekForLoopStack(ForLoopStack *stack);
void freeForLoopStack(ForLoopStack *stack);

#endif