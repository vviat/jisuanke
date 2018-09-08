#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node *pre;
    struct Node *next;
} ListNode;
/**
 * 已经定义的 ListNode 结点
 * typedef struct Node {
 *     int val;
 *     struct Node *pre;
 *     struct Node *next;
 * } ListNode;
 */
ListNode* twoWayLinkListUnique(ListNode *head) {
    int len[1000] = {0};
    ListNode *p, *q;
    p = head;
    // while (p) {
    //     if (len[p->val] == 1) {
    //         q = p->next;
    //         p->pre->next = q;
    //         if(q == NULL) break;
    //         q->pre = p->pre;
    //         p = q;          
    //     } else {
    //         len[p->val] = 1;
    //         p = p->next;
    //     }
    // }
    len[p->val] = 1;
    while(p->next) {
        if (len[p->next->val]) {
            q = p->next->next;
            p->next = q;
            p = q;
        } else {
            len[p->next->val] = 1;
            p = p->next;
        }
    }
    return head;
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
        temp->next->pre = temp;
        temp = temp->next;
    }
    temp = head;
    head = head->next;
    head->pre = NULL;
    free(temp);
    head = twoWayLinkListUnique(head);
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
