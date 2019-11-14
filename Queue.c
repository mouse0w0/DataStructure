#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

Queue InitQueue() {
    Queue queue = malloc(sizeof(Node));
    queue->next = queue;
    return queue;
}

bool IsEmptyQueue(Queue queue) {
    return queue->next == queue;
}

void Enqueue(Queue queue, ElementType value) {
    PtrNode node = malloc(sizeof(Node));
    node->value = value;
    node->next = queue->next;
    queue->next = node;
}

bool Dequeue(Queue queue, ElementType *value) {
    if (IsEmptyQueue(queue)) {
        return false;
    }

    PtrNode node = queue;
    while (node->next->next != queue) {
        node = node->next;
    }
    *value = node->next->value;
    node->next = node->next->next;
    return true;
}


