#ifndef LABEL_STACK_H
#define LABEL_STACK_H

#include <stdlib.h>

typedef struct {
    char *loopLabel;
    char *exitLabel;
} Labels;
typedef struct LabelStackNode {
    Labels *labels;
    struct LabelStackNode *next;
} LabelStackNode;

typedef struct {
    LabelStackNode *top;
} LabelStack;

LabelStack* createLabelStack();
void pushLabelStack(LabelStack **stack, Labels *labels);
Labels* popLabelStack(LabelStack *stack);
Labels* peekLabelStack(LabelStack *stack);
void freeLabelStack(LabelStack *stack);

#endif // LABEL_STACK_H