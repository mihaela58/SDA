#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* anterior = NULL;
    struct ListNode* curent = head;
    struct ListNode* urmator;

    while (curent != NULL) {
        urmator = curent->next;
        curent->next = anterior;
        anterior = curent;
        curent = urmator;
    }

    return anterior;
}

struct ListNode *newNode(int val) {
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void printList(struct ListNode *head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
  
    struct ListNode *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Original: ");
    printList(head);

    head = reverseList(head);

    printf("Reversed: ");
    printList(head);

    return 0;
}