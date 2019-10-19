#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef enum {
    false = 0, true = 1
} bool;
typedef char ElementType;
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
    PStack stack = InitStack();
    char c, t;
    printf("Input Expression:");
    while ((c = getchar()) != '\n') {
        switch (c) {
            case '(':
            case '[':
            case '{':
                Push(stack, c);
                break;
            case ')':
                Pop(stack, &t);
                if (t != '(') {
                    printf("No");
                    return 1;
                }
                break;
            case ']':
                Pop(stack, &t);
                if (t != '[') {
                    printf("No");
                    return 1;
                }
                break;
            case '}':
                Pop(stack, &t);
                if (t != '{') {
                    printf("No");
                    return 1;
                }
                break;
            default:
                break;
        }
    }
    if (IsEmpty(stack)) {
        printf("Yes");
    } else {
        printf("No");
    }
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