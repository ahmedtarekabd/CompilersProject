#ifndef GENERIC_STACK_H
#define GENERIC_STACK_H

#include <stdlib.h>

typedef struct GenericStackNode {
    void *data;  // Generic data pointer
    struct GenericStackNode *next;
} GenericStackNode;

typedef struct {
    GenericStackNode *top;
} GenericStack;

GenericStack* createStack();
void push(GenericStack **stack, void *data);
void* pop(GenericStack *stack);
void* peek(GenericStack *stack);
void freeStack(GenericStack *stack, void (*freeData)(void*));

#endif // GENERIC_STACK_H
