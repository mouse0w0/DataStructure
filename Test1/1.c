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
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &X);
        P = Find(L, X);
        if (P == ERROR)
            printf("Finding Error: %d is not in.\n", X);
        else {
            flag = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if (flag == false)
                printf("Wrong Answer.\n");
        }
    }
    flag = Insert(L, X, NULL);
    if (flag == false) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position) malloc(sizeof(struct LNode));
    flag = Insert(L, X, P);
    if (flag == true) printf("Wrong Answer\n");
    flag = Delete(L, P);
    if (flag == true) printf("Wrong Answer\n");
    for (P = L->Next; P; P = P->Next) printf("%d ", P->Data);
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

void Paint(List L) {
    if (L->Next == NULL) {
        printf("Empty List!\n");
    }
    for (PtrToLNode Node = L->Next; Node != NULL; Node = Node->Next) {
        printf("%d ");
    }
    printf("\n");
}