#include "Stack.h"
#include <stdlib.h>

TreeStack *initStack() {
    TreeStack *stack = malloc(sizeof(TreeStack));
    stack->top = -1;
    for (int i = 0; i < MAXSIZE; i++) {
        stack->data[i] = 0;
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

void addData(int data, TreeStack *stack) {
    stack->top++;
    stack->data[stack->top] = data;
}

void deleteData(TreeStack *stack) {
    if (hasData(stack)) {
        stack->data[stack->top] = 0;
        stack->top--;
    } else {
        return;
    }
}
