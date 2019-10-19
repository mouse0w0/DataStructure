#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef enum {
    false = 0, true = 1
} bool;
typedef int ElementType;
typedef struct {
    ElementType array[MAX_SIZE];
    int top;
} Stack;
typedef Stack *PStack;

PStack InitStack();

bool IsEmpty(PStack stack);

bool Push(PStack stack, ElementType value);

bool Pop(PStack stack, ElementType *value);

int main() {
    printf("Input Number:");
    int n;
    scanf("%d", &n);
    PStack stack = InitStack();
    while (n != 0) {
        Push(stack, n % 2);
        n /= 2;
    }
    while (Pop(stack, &n)) {
        printf("%d", n);
    }
    printf("\n");
    return 0;
}

PStack InitStack() {
    PStack stack = malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

bool IsEmpty(PStack stack) {
    return stack->top == -1;
}

bool Push(PStack stack, ElementType value) {
    if (stack->top == MAX_SIZE - 1) {
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

