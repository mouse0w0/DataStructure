//
// Created by Mouse on 2019/11/14.
//
#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H

#include "Bool.h"

typedef int ElementType;
typedef struct Node *PtrNode;
typedef struct Node {
    ElementType value;
    PtrNode next;
} Node;
typedef PtrNode Queue;

Queue InitQueue();

bool IsEmpty(Queue queue);

void Enqueue(Queue queue, ElementType value);

bool Dequeue(Queue queue, ElementType *value);

#endif //DATASTRUCTURE_QUEUE_H
