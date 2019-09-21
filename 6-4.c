#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist(); /*裁判实现，细节不表*/
struct ListNode *reverse(struct ListNode *head);

void printlist(struct ListNode *head) {
    struct ListNode *p = head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    struct ListNode *head;

    head = createlist();
    head = reverse(head);
    printlist(head);

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *reverse(struct ListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    struct ListNode *Node = head;
    struct ListNode *NextNode = Node->next;
    head->next = NULL;
    while (NextNode != NULL) {
        struct ListNode *NextOfNextNode = NextNode->next;
        NextNode->next = Node;
        Node = NextNode;
        NextNode = NextOfNextNode;
    }
    return Node;
}