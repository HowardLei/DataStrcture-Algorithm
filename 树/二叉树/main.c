#include <stdio.h>
#include "Stack.h"
#include "Tree.h"
void stack() {
    TreeStack *stack = initStack();
    inStack(3, stack);
    inStack(5, stack);
}

int main(int argc, const char * argv[]) {
    BiTree tree = initTree();
    InsertNodeFromLeft(12, tree);
    InsertNodeFromRight(23, tree);
    InsertNodeFromLeft(1, tree->leftChild);
    DLR(tree);
    return 0;
}
