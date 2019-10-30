#include <stdio.h>
#include <stdlib.h>

typedef enum {
    false = 0, true = 1
} bool;
typedef struct {
    int car;
    int time;
} ElementType;
typedef struct {
    ElementType *array;
    int size;
    int top;
} Stack;
typedef Stack *PStack;

PStack InitStack(int size);

bool IsEmpty(PStack stack);

bool IsFull(PStack stack);

bool Push(PStack stack, ElementType value);

bool Pop(PStack stack, ElementType *value);

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
    int n;
    scanf("%d", &n);
    PStack packing = InitStack(n);
    PStack temp = InitStack(n);
    Queue waiting = InitQueue();
    char mode;
    int car, time;
    while (scanf("%c %d %d", &mode, &car, &time)) {
        ElementType data = {car, time};
        switch (mode) {
            case 'A':
                if (IsFullStack(packing)) {
                    Enqueue(waiting, data);
                } else {
                    Push(packing, data);
                }
                break;
            case 'D':
                while (!IsEmptyStack(packing)) {
                    Pop(packing, &data);
                    if (data.car == car) {
                        printf("D %d %d\n", data.car, time - data.time);
                    } else {
                        Push(temp, data);
                    }
                }
                while (!IsEmptyStack(temp)) {
                    Pop(temp, &data);
                    Push(packing, data);
                }
                if (!IsEmptyQueue(waiting)) {
                    Dequeue(waiting, &data);
                    data.time = time;
                    Push(packing, data);
                }
                break;
            case 'E':
                return 0;
        }
    }
    return 0;
}

PStack InitStack(int size) {
    PStack stack = malloc(sizeof(Stack));
    stack->size = size;
    stack->array = malloc(size * sizeof(ElementType));
    stack->top = -1;
    return stack;
}

bool IsEmpty(PStack stack) {
    return stack->top == -1;
}

bool IsFull(PStack stack) {
    return stack->top == stack->size - 1;
}

bool Push(PStack stack, ElementType value) {
    if (IsFull(stack)) {
        return false;
    }

    stack->top++;
    stack->array[stack->top] = value;
    return true;
}

bool Pop(PStack stack, ElementType *value) {
    if (IsEmpty(stack))
        return false;

    *value = stack->array[stack->top];
    stack->top--;
    return true;
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