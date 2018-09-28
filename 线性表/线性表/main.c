#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 128
/*
 线性表
 1、有 0 个元素或多个元素s组成的有限序列。（元素数量是有限个）
    1）什么是有限序列？即元素之间有先来后到关系
    2）若有多个元素，则第一个元素无前驱，最后一个元素没后继。其他元素有且只有一个前驱和后继。如果不满足这个条件就不是线性表。
    3）表中的元素数即为表长。当表长为 0 的时候，即为空表。
 */
/*
 线性表的基本操作
 1、线性表的初始化 Init_List(L) 创建空间制造一个空表
 2、线性表的长度 Length_List(L) 返回线性表中的长度
 3、取表元 Get_List(L, i) 返回第 i 个元素的值
 4、按值查找 Locate_List(L,x) 返回这个值首次存在的地址或值。否则返回 NULL
 5、插入操作 Insert_List(L, i, x) 在 L 表的第 i 个位置插入值为 x 的新元素。插入后表长 = 原表长 + 1
 6、删除操作 Delete_List(L, i) 删除 L 表中第 i 个元素，并且将后边的元素向前移动一位，将表长 -1
 7、清空操作 Clear_List(L), 清空表中的所有元素
 */
// 创建一个表
typedef struct{
    int id[MAXSIZE];
    int last;
}SeqList;
/**
 初始化表
 @return 已经初始化好的表
 */
SeqList *Init_List()  {
    SeqList *list = malloc(sizeof(SeqList));
    list->last = -1;
    for (int i = 0; i < MAXSIZE; i++) {
        list->id[i] = 0;
    }
    return list;
}
/**
 表的长度

 @param list 表
 @return 表长
 */
int Length_List(SeqList *list) {
    // 由于表中元素元素就是 last 指针的
    return (list->last) + 1;
}
/**
 向表中添加元素

 @param list 表
 @param data 添加数据
 @param location 数据所添加的位置的索引（遵守 C 语言的规则）
 */
void Insert_List(SeqList *list, int location, int data) {
    // 一、判断插入元素的位置是否正确，如果不正确不让插入
    if (location > MAXSIZE || location < 0) {
        printf("对不起，无法操作\n");
    } else if (location < list->last) {
        printf("对不起，插入位置有误\n");
    } else {
        // 1、先移动数据，注意：从最后一个开始挪动，挪动到添加的位置
        for (int i = list->last; i > location; i--) {
            list->id[i] = list->id[i - 1];
        }
        // 2、向空的空间中添加元素
        list->id[location] = data;
        // 3、增加 last 值
        list->last++;
    }
}
/**
 删除表中指定位置的元素

 @param list 操作的表
 @param location 元素的位置
 */
void Delete_List(SeqList *list, int location) {
    if (location > MAXSIZE || location < 0) {
        printf("对不起，无法操作");
    } else if (location > list->last) {
        printf("对不起，此位置无元素\n");
    } else {
        // 2、将其他位置的元素往前挪
        for (int i = location; i < list->last; i++) {
            list->id[i] = list->id[i + 1];
        }
        list->last--;
    }
}
/**
 获得表中元素的位置

 @param list 表
 @param data 数据
 @return 元素位置，如果没有，返回 0
 */
int Get_List(SeqList *list, int data) {
    // 遍历整个表，查看这个表里有没有此元素。
    for (int i = 0; i < Length_List(list); i++) {
        if (data == list->id[i]) {
            // 注意：返回的是位置
            return i;
        }
    }
    return 0;
}

// 释放表的内存
void Destory_List(SeqList *list) {
    free(list);
}
int main(int argc, const char * argv[]) {
    SeqList *s1 = Init_List();
    for (int i = 0; i <= MAXSIZE - 1; i++) {
        Insert_List(s1, i, arc4random_uniform(128));
    }
    for (int i = 0; i < Length_List(s1); i++) {
        printf("%d:%d\n", i, s1->id[i]);
    }
    Destory_List(s1);
    return 0;
}
