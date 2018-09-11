#include <stdio.h>
typedef struct {
    int *arr;
    int head;
    int tail;
    int len;
} Queue;

int init(Queue *q, int size) {
    q->arr = (int *)malloc(size * sizeof(int));
    if (q->arr == NULL) return 0;
    q->len = size;
    q->head = 0;
    q->tail = 0;
    return 1;
}
 
int push(Queue *q, int a) {
    if ((q->tail + 1) % q->len == q->head) {
        return 0;
    }
    q->arr[q->tail++] = a;
    q->tail %= q->len;
    return 1;
}
 
int pop(Queue *q) {
    int a = 0;
    if (q->head != q->tail) {
        a = q->arr[q->head++];
        q->head %= q->len;
    }
    return a;
}

int countOff(int n, int m) {
    int i, j, pre_num;
    Queue *q = (Queue *)malloc(sizeof(Queue));
    init(q, n + 1);
    for (i = 1; i <= n; ++i) {
        push(q, i);
    }
    for (i = 1; i < n; ++i) {
        j = m - 1;
        pre_num = pop(q);
        while (j--) {
            push(q, pre_num);
            pre_num = pop(q);
        }
    }
    return pop(q);
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d\n", countOff(n, m));
    return 0;
}
