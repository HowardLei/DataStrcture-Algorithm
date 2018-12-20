//
//  Tree.h
//  哈夫曼树
//
//  Created by jyz on 2018/12/20.
//

#ifndef Tree_h
#define Tree_h

#include <stdio.h>
typedef struct tree {
    int data;
    struct tree *left;
    struct tree *right;
} *Tree;

#endif /* Tree_h */
