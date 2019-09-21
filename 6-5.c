#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

List Insert(List L, ElementType X);

int main() {
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Insert(List L, ElementType X) {
    if (L == NULL || L->Data > X) {
        PtrToNode NewNode = malloc(sizeof(PtrToNode));
        NewNode->Data = X;
        NewNode->Next = L;
        return NewNode;
    }
    PtrToNode Node = L;
    while (Node->Next != NULL) {
        if (Node->Next->Data > X) {
            PtrToNode NewNode = malloc(sizeof(PtrToNode));
            NewNode->Data = X;
            NewNode->Next = Node->Next;
            Node->Next = NewNode;
            return L;
        }
        Node = Node->Next;
    }
    PtrToNode NewNode = malloc(sizeof(PtrToNode));
    NewNode->Data = X;
    NewNode->Next = Node->Next;
    Node->Next = NewNode;
    return L;
}