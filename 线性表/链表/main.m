#import <Foundation/Foundation.h>
/*
 链式存储结构：用任意存储单元存储线性表中的元素，这个位置可以是内存中的任意位置。因为他是通过指针进行连接的。
    存储元素信息的域是数据域，存储直接后继位置的域称为指针域。
    n 个结点链接成一个单向链表称之为单链表。
    链表中的第一个结点存储的位置叫做头指针（头指针的数据域不存储任何数据，它只是具有标识作用，所以常作为链表的名字），最后一个结点指针为 NULL
    无论链表是否为空，头指针均不为空。因为头指针是链表的必要元素。
 注意：存储的内容与顺序表不相同的是：顺序表存储的是位置，而链表存储的是元素以及后继元素所处的地址。
 */
// 创建一个链表的结构。注意：这个链表当中。头指针变量用 LinkList 变量来表示。结点变量用 Lnode 来表示。
typedef struct inode{
    int data;
    struct inode *next;
} Lnode, *LinkList;

/**
 创建一个链表
 @return 链表
 */
LinkList createAList() {
    // 1、创建一个链表
    LinkList s1 = malloc(sizeof(LinkList));
    // 2、创建一个结点
    Lnode *node = malloc(sizeof(Lnode));
    int a = 0;
    scanf("%d", &a);
    node->data = a;
    // 最后返回链表
    return s1;
}
/**
 删除链表中的节点
 @param node 被删结点
 */
void deleteNode(LinkList node) {
    node->next = NULL;
    node->data = 0;
    free(node);
}
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        LinkList l1 = createAList();
        Lnode *s1 = malloc(sizeof(Lnode));
    }
    return 0;
}
