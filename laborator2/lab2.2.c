#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *a = headA;
    struct ListNode *b = headB;

    while (a != b) {
        if (a == NULL) {
            a = headB;
        } else {
            a = a->next;
        }

        if (b == NULL) {
            b = headA;
        } else {
            b = b->next;
        }
    }

    return a;
}

struct ListNode *newNode(int val) {
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main() {
 
    struct ListNode *common = newNode(8);
    common->next = newNode(4);
    common->next->next = newNode(5);

    struct ListNode *headA = newNode(4);
    headA->next = newNode(1);
    headA->next->next = common;

    struct ListNode *headB = newNode(5);
    headB->next = newNode(6);
    headB->next->next = newNode(1);
    headB->next->next->next = common;

    struct ListNode *result = getIntersectionNode(headA, headB);

    if (result != NULL)
        printf("Intersection at node with value: %d\n", result->val);
    else
        printf("No intersection\n");

 
    struct ListNode *x = newNode(1);
    struct ListNode *y = newNode(2);
    result = getIntersectionNode(x, y);

    if (result != NULL)
        printf("Intersection at node with value: %d\n", result->val);
    else
        printf("No intersection\n");

    return 0;
}