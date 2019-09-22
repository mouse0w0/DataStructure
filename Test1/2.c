#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef enum {
    false, true
} bool;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty();

Position Find(List L, ElementType X);

bool Insert(List L, ElementType X, Position P);

bool Delete(List L, Position P);

void Print(List L);

void Sort(List L);

int main() {
    List L;
    ElementType X;
    Position P;
    int N;
    bool flag;

    L = MakeEmpty();
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &X);
        flag = Insert(L, X, L->Next);
        if (flag == false) printf("Wrong Answer\n");
    }
    Sort(L);
    Print(L);
    return 0;
}

/* 你的代码将被嵌在这里 */

List MakeEmpty() {
    List list = malloc(sizeof(List));
    list->Next = NULL;
    return list;
}

Position Find(List L, ElementType X) {
    Position Node = L->Next;
    while (Node != NULL) {
        if (Node->Data == X) {
            return Node;
        }
        Node = Node->Next;
    }
    return ERROR;
}

bool Insert(List L, ElementType X, Position P) {
    Position Node = L;
    while (Node != NULL) {
        if (Node->Next == P) {
            PtrToLNode NewNode = malloc(sizeof(PtrToLNode));
            NewNode->Data = X;
            Node->Next = NewNode;
            NewNode->Next = P;
            return true;
        }
        Node = Node->Next;
    }
    printf("Wrong Position for Insertion\n");
    return false;
}

bool Delete(List L, Position P) {
    Position Node = L;
    while (Node != NULL) {
        if (Node->Next == P) {
            Node->Next = P->Next;
            return true;
        }
        Node = Node->Next;
    }
    printf("Wrong Position for Deletion\n");
    return false;
}

void Print(List L) {
    if (L->Next == NULL) {
        printf("Empty List!\n");
    }
    for (PtrToLNode Node = L->Next; Node != NULL; Node = Node->Next) {
        printf("%d ", Node->Data);
    }
    printf("\n");
}

void Sort(List L) {
    if (L->Next == NULL) {
        return;
    }

    ElementType temp;
    PtrToLNode End = NULL;
    for (PtrToLNode Node = L->Next; Node != NULL; Node = Node->Next) {
        PtrToLNode J;
        for (J = L->Next; J->Next != End; J = J->Next) {
            if (J->Data > J->Next->Data) {
                temp = J->Data;
                J->Data = J->Next->Data;
                J->Next->Data = temp;
            }
        }
        End = J->Next;
    }
}