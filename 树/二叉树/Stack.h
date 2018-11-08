#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <stdbool.h>
#include "Tree.h"
#define MAXSIZE 1024
/*
 栈：是一种限制在表的一端进行添加和删除的线性表，允许插入、删除这一端称为栈顶，另一个固定端称为栈底。所以栈又称为后进先出的线性表（Last In First Out），简称LIFO表。
 */
// 设置一个栈，数组中存放元素，并且保留一个 top 指针。用来判断栈顶元素。
typedef struct stack{
    struct bitnode *data[MAXSIZE];
    int top;
} TreeStack;

/**
 初始化一个栈
 @return 新的栈空间
 */
TreeStack *initStack(void);
/**
 判断栈中有无数据
 @param stack 栈空间
 @return true || false
 */
bool hasData(TreeStack *stack);
/**
 判断栈是否满了
 @param stack 需要判断的栈
 @return 满为 true ，不满为 false 。
 */
bool stackFull(TreeStack *stack);
/**
 向栈中添加元素
 @param node 结点位置
 @param stack 栈
 */
void inStack(struct bitnode *node, TreeStack *stack);

/**
 出栈算法
 @param stack 栈
 @return 结点位置
 */
struct bitnode *outStack(TreeStack *stack);
/**
 释放栈空间
 @param stack 需要释放的栈
 */
void freeStack(TreeStack *stack);
/**
 遍历栈中的所有元素
 @param stack 需要遍历的栈空间
 */
void traversalStack(TreeStack *stack);
#endif /* Stack_h */
