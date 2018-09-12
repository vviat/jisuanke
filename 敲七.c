#include <stdio.h>
#include<stdlib.h>
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

int empty(Queue *q) {
    return q->head == q->tail;
}

int seven(int num) {
    if (num % 7 == 0) return 1;
    while (num) {
        if (num % 10 == 7) return 1;
        num /= 10;
    }
    return 0;
}
 

int strikeSeven(int n, int index, int number) {
    int i, pre_num;
    Queue *q = (Queue *)malloc(sizeof(Queue));
    init(q,n + 1);
    for (i = 0; i < n; ++i) {
        push(q, (index + i - 1) % n + 1);
    }
    while (!empty(q)) {
        pre_num = pop(q);
        if (!seven(number)) {
            push(q, pre_num);
        }
        ++number;
    }
    return pre_num;
}
char name[1024][20];
int main() {
    int n, index, number;
    scanf("%d %d %d", &n, &index, &number);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", name[i]);
    }
    printf("%s\n", name[strikeSeven(n, index, number)]);
    return 0;
}
