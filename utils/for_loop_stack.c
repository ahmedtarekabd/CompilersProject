#include "for_loop_stack.h"
#include <stdio.h>

ForLoopStack* createForLoopStack() {
    ForLoopStack *stack = (ForLoopStack *)malloc(sizeof(ForLoopStack));
    stack->top = NULL;
    return stack;
}

void pushForLoopStack(ForLoopStack **stack, ForLoopAttributes *forLoopAttributes) {
    // Check if the stack is empty
    if (*stack == NULL) {
        printf("stack is empty\n");
        *stack = createForLoopStack();
    }
    forLoopStackNode *node = (forLoopStackNode *)malloc(sizeof(forLoopStackNode));
    node->forLoopAttributes = forLoopAttributes;
    node->next = (*stack)->top;
    (*stack)->top = node;
    printf("pushing loop stack\n");
}

ForLoopAttributes* popForLoopStack(ForLoopStack *stack) {
    if (stack == NULL) {
        return NULL;
    }
    forLoopStackNode *node = stack->top;
    ForLoopAttributes *forLoopAttributes = node->forLoopAttributes;
    stack->top = node->next;
    free(node);
    return forLoopAttributes;
}

ForLoopAttributes* peekForLoopStack(ForLoopStack *stack) {
    if (stack->top == NULL) {
        return NULL;
    }
    return stack->top->forLoopAttributes;
}

void freeForLoopStack(ForLoopStack *stack) {
    while (stack->top != NULL) {
        popForLoopStack(stack);
    }
    free(stack);
}