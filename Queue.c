#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef enum {
    false = 0, true = 1
} bool;
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

int main() {
    return 0;
}

Queue InitQueue() {
    Queue queue = malloc(sizeof(Node));
    queue->next = queue;
    return queue;
}

bool IsEmpty(Queue queue) {
    return queue->next == queue;
}

void Enqueue(Queue queue, ElementType value) {
    PtrNode node = malloc(sizeof(Node));
    node->value = value;
    node->next = queue->next;
    queue->next = node;
}

bool Dequeue(Queue queue, ElementType *value) {
    if (IsEmpty(queue)) {
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


