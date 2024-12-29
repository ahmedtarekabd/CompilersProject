#include "label_stack.h"
#include <stdio.h>

LabelStack* createLabelStack() {
    LabelStack *stack = (LabelStack *)malloc(sizeof(LabelStack));
    stack->top = NULL;
    return stack;
}

void pushLabelStack(LabelStack **stack, Labels *labels) {
    // Check if the stack is empty
    if (*stack == NULL) {
        printf("stack is empty\n");
        *stack = createLabelStack();
    }
    LabelStackNode *node = (LabelStackNode *)malloc(sizeof(LabelStackNode));
    node->labels = labels;
    node->next = (*stack)->top;
    (*stack)->top = node;
    printf("pushing label stack\n");
}

Labels* popLabelStack(LabelStack *stack) {
    if (stack == NULL) {
        return NULL;
    }
    LabelStackNode *node = stack->top;
    Labels *labels = node->labels;
    stack->top = node->next;
    free(node);
    return labels;
}

Labels* peekLabelStack(LabelStack *stack) {
    if (stack->top == NULL) {
        return NULL;
    }
    return stack->top->labels;
}

void freeLabelStack(LabelStack *stack) {
    while (stack->top != NULL) {
        popLabelStack(stack);
    }
    free(stack);
}