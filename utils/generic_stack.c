#include "generic_stack.h"
#include <stdio.h>

GenericStack* createStack() {
    GenericStack *stack = (GenericStack *)malloc(sizeof(GenericStack));
    stack->top = NULL;
    return stack;
}

void push(GenericStack **stack, void *data) {
    if (*stack == NULL) {
        *stack = createStack();
    }
    GenericStackNode *node = (GenericStackNode *)malloc(sizeof(GenericStackNode));
    node->data = data;
    node->next = (*stack)->top;
    (*stack)->top = node;
}

void* pop(GenericStack *stack) {
    if (stack == NULL || stack->top == NULL) {
        return NULL;
    }
    GenericStackNode *node = stack->top;
    void *data = node->data;
    stack->top = node->next;
    free(node);
    return data;
}

void* peek(GenericStack *stack) {
    if (stack == NULL || stack->top == NULL) {
        return NULL;
    }
    return stack->top->data;
}

void freeStack(GenericStack *stack, void (*freeData)(void*)) {
    while (stack && stack->top != NULL) {
        GenericStackNode *node = stack->top;
        stack->top = node->next;
        if (freeData) {
            freeData(node->data);
        }
        free(node);
    }
    free(stack);
}
