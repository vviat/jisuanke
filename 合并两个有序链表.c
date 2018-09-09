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
ListNode* mergeTwoSortedLinkList(ListNode *l1, ListNode *l2) {
    if (!l1 && !l2) return NULL;
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode *head, *p;
    if (l1->val < l2->val){
        head = p = l1;
        l1 = l1->next;
    }
    else {
        head = p = l2;
        l2 = l2->next;
    }
    while (l1 && l2){
        if (l1->val < l2->val){
            p->next = l1;
            l1 = l1->next;
        }
        else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    if (!l1){
        p->next = l2;
    }
    if (!l2){
        p->next = l1;
    }
    return head;
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
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
    temp = head;
    head = head->next;
    free(temp);
    ListNode *head2 = (ListNode*)malloc(sizeof(ListNode));
    head2->val = 0;
    head2->next = NULL;
    temp = head2;
    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        temp->next = (ListNode*)malloc(sizeof(ListNode));
        temp->next->val = x;
        temp->next->next = NULL;
        temp = temp->next;
    }
    temp = head2;
    head2 = head2->next;
    free(temp);
    head = mergeTwoSortedLinkList(head, head2);
    temp = head;
    while (head) {
        printf("%d ", head->val);
        head = head->next;
        free(temp);
        temp = head;
    }
    printf("\n");
    return 0;
}
