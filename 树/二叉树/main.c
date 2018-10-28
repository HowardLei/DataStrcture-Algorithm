#include <stdio.h>
#include <stdlib.h>
/*
 一、二叉树的定义
 二叉树(Binary Tree)是个有限元素的集合，该集合或者为空、或者由一个称为根(root)的元素及两个不相交的、被分别称为左子树和右子树的二叉树
 ● 当集合为空时，称为空二叉树
 ● 在二叉树中，一个元素也称作一个结点
 二、二叉树的相关概念
 1、结点的度
 结点所拥有的子树个数称为该结点的度
 2、叶结点
 度为0的结点称为叶结点，或者称为终端结点
 3、分枝结点
 度不为0的结点称为分支结点，或者称为非终端结点
 4、左孩子、右孩子、双亲、兄弟
 树中一个结点的子树根结点称为该结点的孩子。其中，左子树的根称为左孩子，右子树的根称为右孩子。该结点称为其子女结点的双亲(或父结点)。具有同一个双亲的孩子结点互称为兄弟。
 5、路径、路径长度
 若树中一个结点序列n1,n2,…,nk有如下关系：结点ni是ni+1的父结点(1≤i<k)，则n1,n2,…,nk称为由n1至nk的路径。路径的长度是k-1
 6、祖先、子孙
 若一条路径从结点M到N，则M称为N的祖先，N称为M的子孙
 7、结点的层数
 树的根结点层数为1，其余结点的层数等于它的双亲结点的层数加1
 8、树的深度
 树中所有结点的最大层数称为树的深度
 9、树的度
 树中各结点度的最大值称为该树的度
 10、满二叉树
 一棵二叉树，若所有分支结点都存在左子树和右子树，且所有叶子结点都在同一层上，则称为满二叉树
 11、 完全二叉树
 一棵深度为k，且有n个结点的二叉树。对树中的结点按从上至下、从左到右的顺序进行编号。若编号为i(1≤i≤n)的结点与满二叉树中编号为i的结点在二叉树中的位置相同，则称为完全二叉树。特点是：叶子结点只能出现在最下层和次下层，且最下层的叶子结点集中在树的左部
 */
// 创建一棵树（含有左右结点的树）
typedef struct bitnode{
    int data;
    struct bitnode *leftChild, *rightChild;
} TreeNode, *BiTree;
// 初始化一棵树
BiTree init() {
    BiTree tree = malloc(sizeof(BiTree));
    tree->data = 0;
    tree->leftChild = NULL;
    tree->rightChild = NULL;
    return tree;
}
/**
 在左结点上添加数据
 @param data 添加的数据
 @param tree 双亲的结点
 @return 形成的新树
 */
BiTree InsertNodeFromLeft(int data, BiTree tree) {
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
        return NULL;
    }
    return tree;
}
BiTree InsertNodeFromRight(int data, BiTree tree){
    TreeNode *node = malloc(sizeof(TreeNode));
    node->data = data;
    if (tree->rightChild == NULL) {
        tree->rightChild = node;
    } else {
        printf("对不起，树已经有右子女了");
        return NULL;
    }
    return tree;
}
/**
 生成一棵以 data 为根结点的数据域值以 lbt 和 rbt 为左右子树的二叉树
 @param data 保存的数据
 @param lbt 左子树
 @param rbt 右子树
 @return 创建好的子树
 */
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
/**
 删除一棵树
 @param tree 树的结点
 */
void FreeTree(BiTree tree);
/*
 有关二叉树的遍历，有三种方法：前序遍历，中序遍历，后序遍历，广度遍历。
 */
void visitNode(BiTree tree){
    TreeNode *node = tree;
}
/**
 树的前序遍历
 算法：若二叉树为空，遍历结束。否则，
 ⑴ 访问根结点；
 ⑵ 先序遍历根结点的左子树；
 ⑶ 先序遍历根结点的右子树。
 @param tree 树的结点
 */
void DLR(BiTree tree) {
    printf("%d\n", tree->data);
    if (tree != NULL) {
        visitNode(tree);
        DLR(tree->leftChild);
        DLR(tree->rightChild);
    } else {
        return;
    }
}
/**
 树的中序遍历
 @param tree 树的结点
 */
void LDR(BiTree tree) {
    if (tree != NULL) {
    }
}
/**
 树的后续遍历
 @param tree 树的结点
 */
void LRD(BiTree tree) {
    if (tree != NULL) {
    }
}
int main(int argc, const char * argv[]) {
    BiTree tree = init();
    tree->leftChild = InsertNodeFromLeft(12, tree);
    tree->rightChild = InsertNodeFromRight(23, tree);
    printf("%d\n", tree->leftChild->data);
    return 0;
}
