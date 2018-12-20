//
//  Queue.h
//  哈夫曼树
//
//  Created by jyz on 2018/12/20.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>

typedef struct queue {
    int front;
    int rear;
    // 动态数组
    int *data;
    // 数组大小
    int maxsize;
} *Queue;
/**
 初始化一个队列
 @param maxsize 队列需要多长
 */
Queue InitQueue(int maxsize);
void InQueue(int data, Queue q);
int OutQueue(Queue q);
#endif /* Queue_h */
