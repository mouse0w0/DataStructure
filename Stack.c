#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

PStack InitStack(int size) {
    PStack stack = malloc(sizeof(Stack));
    stack->size = size;
    stack->array = malloc(size * sizeof(ElementType));
    stack->top = -1;
    return stack;
}

bool IsEmptyStack(PStack stack) {
    return stack->top == -1;
}

bool IsFullStack(PStack stack) {
    return stack->top == stack->size - 1;
}

bool Push(PStack stack, ElementType value) {
    if (IsFullStack(stack)) {
        return false;
    }

    stack->top++;
    stack->array[stack->top] = value;
    return true;
}

bool Pop(PStack stack, ElementType *value) {
    if (IsEmptyStack(stack))
        return false;

    *value = stack->array[stack->top];
    stack->top--;
    return true;
}

