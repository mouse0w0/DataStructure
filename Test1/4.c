#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef enum {
    false, true
} bool;
typedef struct {
    float Factor;
    float Power;
} ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

void Print(List L);

List Read();

List Add(List List1, List List2);

List Sub(List List1, List List2);

int main() {
    List List1 = Read();
    List List2 = Read();

    printf("\n");

    printf("A(x)=");
    Print(List1);

    printf("B(x)=");
    Print(List2);

    printf("C(x)=");
    Print(Add(List1, List2));

    printf("D(x)=");
    Print(Sub(List1, List2));
    return 0;
}

void Print(List L) {
    for (PtrToLNode Node = L; Node != NULL; Node = Node->Next) {
        if (Node != L && Node->Data.Factor > 0) {
            printf("+");
        }
        if (Node->Data.Power == 1) {
            printf("%.1fx", Node->Data.Factor);
        } else if (Node->Data.Power == 0) {
            printf("%.1f", Node->Data.Factor);
        } else {
            printf("%.1fx^%.0f", Node->Data.Factor, Node->Data.Power);
        }
    }
    printf("\n");
}

List Read() {
    int n;
    scanf("%d", &n);
    List List = NULL;
    PtrToLNode PreNode = NULL;
    for (int i = 0; i < n; ++i) {
        PtrToLNode Node = malloc(sizeof(struct LNode));
        float Factor;
        float Power;
        scanf("%f%f", &Factor, &Power);
        Node->Data.Factor = Factor;
        Node->Data.Power = Power;
        if (List == NULL) {
            List = Node;
            PreNode = Node;
        } else {
            PreNode->Next = Node;
            PreNode = Node;
        }
    }

    if (PreNode != NULL) {
        PreNode->Next = NULL;
    }
    return List;
}

List Add(List List1, List List2) {
    PtrToLNode Node1 = List1;
    PtrToLNode Node2 = List2;

    List List = malloc(sizeof(struct LNode));
    PtrToLNode PreNode = List;
    PtrToLNode Node;
    while (Node1 != NULL) {
        while (Node2->Data.Power > Node1->Data.Power) {
            Node = malloc(sizeof(struct LNode));
            Node->Data = Node2->Data;
            PreNode->Next = Node;
            PreNode = Node;
            Node2 = Node2->Next;
        }

        Node = malloc(sizeof(struct LNode));
        Node->Data = Node1->Data;
        if (Node2->Data.Power == Node1->Data.Power) {
            Node->Data.Factor += Node2->Data.Factor;
            Node2 = Node2->Next;
        }
        if (Node->Data.Factor == 0) {
            free(Node);
        } else {
            PreNode->Next = Node;
            PreNode = Node;
        }
        Node1 = Node1->Next;
    }

    while (Node2 != NULL) {
        Node = malloc(sizeof(struct LNode));
        Node->Data = Node2->Data;
        PreNode->Next = Node;
        PreNode = Node;
        Node2 = Node2->Next;
    }

    PreNode->Next = NULL;
    PtrToLNode Head = List->Next;
    free(List);
    return Head;
}

List Sub(List List1, List List2) {
    PtrToLNode Node1 = List1;
    PtrToLNode Node2 = List2;

    List List = malloc(sizeof(struct LNode));
    PtrToLNode PreNode = List;
    PtrToLNode Node;
    while (Node1 != NULL) {
        while (Node2->Data.Power > Node1->Data.Power) {
            Node = malloc(sizeof(struct LNode));
            Node->Data.Power = Node2->Data.Power;
            Node->Data.Factor = -Node2->Data.Factor;
            PreNode->Next = Node;
            PreNode = Node;
            Node2 = Node2->Next;
        }

        Node = malloc(sizeof(struct LNode));
        Node->Data = Node1->Data;
        if (Node2->Data.Power == Node1->Data.Power) {
            Node->Data.Factor -= Node2->Data.Factor;
            Node2 = Node2->Next;
        }
        if (Node->Data.Factor == 0) {
            free(Node);
        } else {
            PreNode->Next = Node;
            PreNode = Node;
        }
        Node1 = Node1->Next;
    }

    while (Node2 != NULL) {
        Node = malloc(sizeof(struct LNode));
        Node->Data.Power = Node2->Data.Power;
        Node->Data.Factor = -Node2->Data.Factor;
        PreNode->Next = Node;
        PreNode = Node;
        Node2 = Node2->Next;
    }

    PreNode->Next = NULL;
    PtrToLNode Head = List->Next;
    free(List);
    return Head;
}