//
// Created by Mouse on 2019/11/14.
//

#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#include "Bool.h"

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

#endif //DATASTRUCTURE_STACK_H
