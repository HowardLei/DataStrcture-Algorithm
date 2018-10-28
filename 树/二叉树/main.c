#include <stdio.h>

#include "Tree.h"
/*
 非递归版先序遍历
 */
int main(int argc, const char * argv[]) {
    BiTree tree = initTree();
    InsertNodeFromLeft(12, tree);
    InsertNodeFromRight(23, tree);
    InsertNodeFromLeft(1, tree->leftChild);
    DLR(tree);
    return 0;
}
