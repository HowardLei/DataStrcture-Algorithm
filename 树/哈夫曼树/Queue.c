//
//  Queue.c
//  哈夫曼树
//
//  Created by jyz on 2018/12/20.
//

#include "Queue.h"
#include <stdlib.h>
Queue InitQueue(int maxsize) {
    int *queue = malloc(maxsize * sizeof(int));
    Queue q = malloc(sizeof(Queue));
    q->maxsize = maxsize;
    q->data = queue;
    q->rear = 0;
    q->front = 0;
    return q;
}

void InQueue(int data, Queue q) {
    * (q->data + q->rear) = data;
    q->rear++;
}

int outQueue(Queue q) {
    int data = *(q->data + q->front);
    q->front++;
    return data;
}
