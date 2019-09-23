#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef enum {
    false, true
} bool;
typedef struct {
    int Index;
    int M;
} ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List Read();

int main() {
    int m;
    scanf("%d", &m);
    PtrToLNode Node = Read();
    while (Node->Next != Node) {
        if (m == 1) {
            printf("%d ", Node->Next->Data.Index);
            m = Node->Next->Data.M;
            Node->Next = Node->Next->Next;
        } else {
            m--;
            Node = Node->Next;
        }
    }
    printf("%d\n", Node->Data.Index);
    return 0;
}

PtrToLNode Read() {
    int n;
    scanf("%d", &n);
    PtrToLNode FirstNode = NULL;
    PtrToLNode PreNode = NULL;
    for (int i = 1; i <= n; ++i) {
        PtrToLNode Node = malloc(sizeof(struct LNode));
        Node->Data.Index = i;
        scanf("%d", &(Node->Data.M));
        if (FirstNode == NULL) {
            FirstNode = Node;
            PreNode = Node;
        } else {
            PreNode->Next = Node;
            PreNode = Node;
        }
    }
    if (FirstNode != NULL) {
        PreNode->Next = FirstNode;
        return PreNode;
    }
    return NULL;
}

