#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 64

// 创建树节点
typedef struct {
    // 结点的权值
    int weight;
    // 结点的双亲
    int parent;
    // 结点的左右子女
    int lchild;
    int rchild;
} TreeNode;

/**
 构建哈夫曼树
 @param Huff 需要构建哈夫曼树的结点
 @param n 结点数量
 */
void HuffmanTree(TreeNode Huff[], int n) {
    // m1, m2 代表的是每次集合中最小的两个权重，x1, x2 即为他们的下标。
    int i, j, m1, m2, x1, x2;
    for (i = 0; i < 2 * n - 1; i++) {
        Huff[i].weight = 0;
        Huff[i].parent = -1;
        Huff[i].lchild = -1;
        Huff[i].rchild = -1;
    }
    printf("Input 1 ~ %d value of leaf:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &Huff[i].weight);
    }
    for (i = 0; i < n - 1; i++) {
        // 为了找到最小值，先默认一个最大的数
        m1 = m2 = 1024;
        x1 = x2 = 0;
        for (j = 0; j < n + i; j++) {
            if (Huff[j].parent == -1 && Huff[j].weight < m1) {
                m2 = m1;
                x2 = x1;
                m1 = Huff[j].weight;
                x1 = j;
            } else if (Huff[j].parent == -1 && Huff[j].weight < m2) {
                m2 = Huff[j].weight;
                x2 = j;
            }
        }
        Huff[x1].parent = n + i;
        Huff[x2].parent = n + i;
        Huff[n + i].weight = Huff[x1].weight + Huff[x2].weight;
        Huff[n + i].lchild = x1;
        Huff[n + i].rchild = x2;
    }
    printf("Huff weight   lchild   rchild   parent\n");
    for (i = 0; i < 2 * n - 1; i++) {
        printf("%3d%5d%10d%10d%10d\n", i, Huff[i].weight, Huff[i].lchild, Huff[i].rchild, Huff[i].parent);
    }
}

int main(int argc, const char * argv[]) {
    // 创建一个结点数组
    TreeNode Huff[MAXSIZE] = {};
    HuffmanTree(Huff, 4);
    return 0;
}
