//
//  Tree.c
//  二叉树
//
//  Created by jyz on 2018/10/28.
//

#include "Tree.h"
#include <stdlib.h>

BiTree initTree() {
    BiTree tree = malloc(sizeof(BiTree));
    tree->data = 0;
    tree->leftChild = NULL;
    tree->rightChild = NULL;
    return tree;
}

void InsertNodeFromLeft(int data, BiTree tree) {
    // 1、创建一个结点z
    TreeNode *node = malloc(sizeof(TreeNode));
    // 2、为结点中添加数据
    node->data = data;
    node->leftChild = NULL;
    node->rightChild = NULL;
    // 3、将结点添加到树的结点上
    if (tree->leftChild == NULL) {
        tree->leftChild = node;
    } else {
        printf("对不起，树有左子女了\n");
        return;
    }
}

void InsertNodeFromRight(int data, BiTree tree){
    TreeNode *node = malloc(sizeof(TreeNode));
    node->data = data;
    node->leftChild = NULL;
    node->rightChild = NULL;
    if (tree->rightChild == NULL) {
        tree->rightChild = node;
    } else {
        printf("对不起，树已经有右子女了");
        return;
    }
}

BiTree create(int data, BiTree lbt, BiTree rbt) {
    BiTree p;
    if ((p = (TreeNode *)malloc(sizeof(TreeNode))) == NULL) {
        return NULL;
    }
    p->data = data;
    p->leftChild = lbt;
    p->rightChild = rbt;
    return p;
}

void DLR(BiTree tree) {
    if (tree != NULL) {
        // visitNode(tree);
        DLR(tree->leftChild);
        DLR(tree->rightChild);
    } else {
        return;
    }
}

void LDR(BiTree tree) {
    if (tree != NULL) {
        LDR(tree->leftChild);
        LDR(tree->rightChild);
    } else {
        return;
    }
}

void LRD(BiTree tree) {
    if (tree != NULL) {
        LRD(tree->leftChild);
        LRD(tree->rightChild);
    } else {
        return;
    }
}

void traverseFromStack(BiTree tree) {
    TreeNode *node = tree;
    TreeStack *stack = initStack();
    inStack(node, stack);
    while (hasData(stack)) {
        TreeNode *node = outStack(stack);
        printf("%d\n", node->data);
        if (node->rightChild) {
            inStack(node->rightChild, stack);
        }
        if (node->leftChild) {
            inStack(node->leftChild, stack);
        }
    }
    freeStack(stack);
}

int leafNodeNumber(BiTree tree) {
    int leafNodes = 0;
    TreeNode *node = tree;
    TreeStack *stack = initStack();
    inStack(node, stack);
    while (hasData(stack)) {
        TreeNode *node = outStack(stack);
        printf("%d\n", node->data);
        if (!(node->leftChild || node->rightChild)) {
            leafNodes++;
        }
        if (node->rightChild) {
            inStack(node->rightChild, stack);
        }
        if (node->leftChild) {
            inStack(node->leftChild, stack);
        }
    }
    freeStack(stack);
    return leafNodes;
}

int oneChildNode(BiTree tree) {
    int oneChilds = 0;
    TreeNode *node = tree;
    TreeStack *stack = initStack();
    inStack(node, stack);
    while (hasData(stack)) {
        TreeNode *node = outStack(stack);
        printf("%d\n", node->data);
        if (node->rightChild) {
            inStack(node->rightChild, stack);
            if (!node->leftChild) {
                oneChilds++;
            }
        }
        if (node->leftChild) {
            inStack(node->leftChild, stack);
            if (!node->rightChild) {
                oneChilds++;
            }
        }
    }
    freeStack(stack);
    return oneChilds;
}

int twoChildNode(BiTree tree) {
    int twoChildNode = 0;
    TreeNode *node = tree;
    TreeStack *stack = initStack();
    inStack(node, stack);
    while (hasData(stack)) {
        TreeNode *node = outStack(stack);
        if (node->leftChild && node->rightChild) {
            twoChildNode++;
        }
        if (node->rightChild) {
            inStack(node->rightChild, stack);
        }
        if (node->leftChild) {
            inStack(node->leftChild, stack);
        }
    }
    freeStack(stack);
    return twoChildNode;
}

void changeNode(TreeNode *node) {
    TreeNode *node1 = node->leftChild;
    node->leftChild = node->rightChild;
    node->rightChild = node1;
}

void changeChild(BiTree tree) {
    TreeNode *node = tree;
    TreeStack *stack = initStack();
    inStack(node, stack);
    while (hasData(stack)) {
        TreeNode *node = outStack(stack);
        if (node->leftChild != NULL || node->rightChild == NULL) {
            changeNode(node);
        }
        if (node->rightChild) {
            inStack(node->rightChild, stack);
        }
        if (node->leftChild) {
            inStack(node->leftChild, stack);
        }
    }
    freeStack(stack);
}

int emptyPointers(BiTree tree) {
    int emptyPointerCount = 0;
    TreeNode *node = tree;
    TreeStack *stack = initStack();
    inStack(node, stack);
    while (hasData(stack)) {
        TreeNode *node = outStack(stack);
        if (node->rightChild) {
            inStack(node->rightChild, stack);
        } else {
            emptyPointerCount++;
        }
        if (node->leftChild) {
            inStack(node->leftChild, stack);
        } else {
            emptyPointerCount++;
        }
    }
    freeStack(stack);
    return emptyPointerCount;
}
// FIXME: 没改完
int treeDepth(BiTree tree) {
    return 0;
}
