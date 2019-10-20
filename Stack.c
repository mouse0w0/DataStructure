#include <stdio.h>
#include <stdlib.h>

typedef enum {
    false = 0, true = 1
} bool;
typedef int ElementType;
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

int main() {
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

