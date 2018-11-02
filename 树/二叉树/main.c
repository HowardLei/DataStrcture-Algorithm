#include <stdio.h>
#include "Stack.h"
#include "Tree.h"

int main(int argc, const char * argv[]) {
    BiTree tree = initTree();
    InsertNodeFromLeft(12, tree);
    InsertNodeFromRight(23, tree);
    InsertNodeFromLeft(1, tree->leftChild);
//    DLR(tree);
    traverseFromStack(tree);
    return 0;
}
