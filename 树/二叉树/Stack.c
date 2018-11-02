#include "Stack.h"
#include <stdlib.h>

TreeStack *initStack() {
    TreeStack *stack = malloc(sizeof(TreeStack));
    stack->top = -1;
    for (int i = 0; i < MAXSIZE; i++) {
        stack->data[i] = NULL;
    }
    return stack;
}

bool hasData(TreeStack *stack) {
    if (stack->top == -1) {
        return false;
    } else {
        return true;
    }
}

bool stackFull(TreeStack *stack) {
    if (stack->top == MAXSIZE - 1) {
        return true;
    } else {
        return false;
    }
}

void inStack(TreeNode *node, TreeStack *stack) {
    stack->top++;
    stack->data[stack->top] = node;
}

TreeNode *outStack(TreeStack *stack) {
    if (hasData(stack)) {
        TreeNode *node = stack->data[stack->top];
        stack->data[stack->top] = 0;
        stack->top--;
        return node;
    } else {
        return NULL;
    }
}
void traversalStack(TreeStack *stack) {
    
}
void freeStack(TreeStack *stack) {
    free(stack);
}
