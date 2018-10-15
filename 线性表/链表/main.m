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
 创建一个链表，并从表头添加元素（倒序添加）
 @return 链表
 */
LinkList createAListFromForward() {
    // 1、创建一个链表头
    LinkList s1 = NULL;
    Lnode *node;
    // 2、设置元素值
    int a = 0;
    NSLog(@"请输入一个值：");
    scanf("%d", &a);
    // 判断元素的值，如果为 -1 ，则取消循环
    while (a != EOF) {
        node = malloc(sizeof(Lnode));
        node->data = a;
        node->next = s1;
        NSLog(@"%p", node->next);
        s1 = node;
        NSLog(@"%d", node->data);
        scanf("%d", &a);
    }
    // 最后返回链表
    return s1;
}
/**
 删除链表中的节点
 @param node 被删结点
 */
void deleteNode(LinkList node) {
    // 1、先找到尾结点
    while (node->next == NULL) {
        
    }
}
/**
 向表中添加元素
 @param list 需要添加元素的表
 */
void addElementFromBackward(LinkList list) {

}
/**
 展示表中的所有元素
 @param list 需要展示的表
 */
void displayAllElement(LinkList list) {
    Lnode *node = list;
    int count = 0;
    while (node->next != NULL) {
        count++;
        NSLog(@"%d", node->data);
        node = node->next;
    }
    NSLog(@"%d", node->data);
}
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        LinkList list = createAListFromForward();
        displayAllElement(list);
    }
    return 0;
}
