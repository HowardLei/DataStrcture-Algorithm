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
    // 由于表中元素元素就是 last 指针的，所以说表的长度为 last + 1
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
 获得表中元素的位置（如果出现多次，则返回元素第一次出现的位置）
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
    return -1;
}
/**
 输入一个值，做一个划分。左边全都是小于等于它的值，右边都是大于它的值
 @param list 表
 @param data 数据
 */
// 注意：这个只是保证左边都是保证要求，并不是完全排序）
void Part(SeqList *list, int data) {
    // 一、创建三个变量。控制起始，终止，中间变量。
    int start = 0, end = 0, temp = 0;
    // 二、遍历这个数组，注意：数组中的遍历不是在第一个 for 循环中写，是通过下边的循环来控制。
    for (start = 0, end = list->last; start < end;) {
    // 控制 start 索引，找到前面比 data 大的值
        for (; start < end; start++) {
            if (list->id[start] > data) {
                break;
            }
        }
    // 控制 end 索引，找到后边比 data 小于等于的值
        for (; start < end; end--) {
            if (list->id[end] <= data) {
                break;
            }
        }
        // 对值进行交换，注意：交换的时候不一定保证 start 的索引比 end 索引小，需要进行判断再进行交换
        if (start < end) {
            temp = list->id[start];
            list->id[start] = list->id[end];
            list->id[end] = temp;
        }
    }
}
/**
 合并多表
 @param list1 表1
 @param list2 表2
 @param list3 合并之后的表
 */
void Merge(SeqList *list1, SeqList *list2, SeqList *list3) {
    int i = 0, j = 0, k = 0;
    while (i <= list1->last && j <= list2->last) {
        if (list1->id[i] < list2->id[i]) {
            list3->id[k++] = list1->id[i++];
        } else {
            list3->id[k++] = list2->id[i++];
        }
    }
    while (i <= list1->last) {
        list3->id[k++] = list1->id[i++];
    }
    while (j <= list2->last) {
        list3->id[k++] = list2->id[j++];
    }
    list3->last = k - 1;
}
/**
 释放表的内存
 @param list 需要释放的表
 */
void Destory_List(SeqList *list) {
    free(list);
}
/**
 为列表排序（升序）
 // 方法：选择排序法
 @param list 需要进行排序的列表
 */
void Sequence(SeqList *list) {
    // 创建 3 个变量，1 个记录索引的，2 个循环变量
    int a, b, c;
    for (a = 0; a < Length_List(list) - 1; a++) {
        c = a;
        for (b = a + 1; b < Length_List(list); b++) {
            if (list->id[c] > list->id[b]) {
                c = b;
            }
        }
        if (c != a) {
            int temp = list->id[c];
            list->id[c] = list->id[a];
            list->id[a] = temp;
        }
    }
}

int main(int argc, const char * argv[]) {
    SeqList *s1 = Init_List();
    for (int i = 0; i < 10; i++) {
        Insert_List(s1, i, arc4random_uniform(14));
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\t", s1->id[i]);
    }
    printf("\n");
    Part(s1, 2);
    for (int i = 0; i < 10; i++) {
        printf("%d\t", s1->id[i]);
    }
    Destory_List(s1);
    return 0;
}
