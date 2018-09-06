#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node *next;
} ListNode;
/**
 * 已经定义的 ListNode 结点
 * typedef struct Node {
 *     int val;
 *     struct Node *next;
 * } ListNode;
 */
ListNode* linkedListCycleLinkedNode(ListNode *head) {
    ListNode *p, *q;
    p = q = head;
    while (q && q->next){
        p = p->next;
        q = q->next->next;
        if (p == q) break;
    }
    if (p != q) return 0;
    int n = 1;
    q = q->next;
   	while (p != q) {
        q = q->next;
        n++;
    }
	p = head, q = head;
    while (n--) {
        q = q->next;
    }
    while (1) {
        if (p == q) return p;
        p = p->next;
        q = q->next;
    }
    return NULL;
}
int main() {
    int n;
    scanf("%d", &n);
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    head->val = 0;
    head->next = NULL;
    ListNode *temp = head;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp->next->val = x;
        temp->next->next = NULL;
        temp = temp->next;
    }
    int d;
    scanf("%d", &d);
    ListNode *Nth = head;
    while (d--) {
        Nth = Nth->next;
    }
    temp->next = Nth;
    temp = head;
    head = head->next;
    free(temp);
    ListNode *node = linkedListCycleLinkedNode(head);
    if (!node) {
        printf("No cycle\n");
    } else {
        printf("%d\n", node->val);
    }
    return 0;
}
