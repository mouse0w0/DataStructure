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
    PtrToNode NewNode = malloc(sizeof(struct Node));
    NewNode->Data = X;
    NewNode->Next = NULL;

    if (L->Next == NULL) {
        L->Next = NewNode;
        return L;
    }

    PtrToNode Node = L;
    PtrToNode Next = L->Next;
    while (Next->Data < X) {
        Node = Next;
        Next = Next->Next;
        if (Next->Next == NULL) {
            Next->Next = NewNode;
            return L;
        }
    }
    NewNode->Next = Next;
    Node->Next = NewNode;
    return L;
}