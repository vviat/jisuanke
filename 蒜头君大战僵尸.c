#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Heap {
    int *data;
    int  size;
} Heap;

typedef struct Js {
    int ssd;
    int msd;
    int bianhao;
} Js;

int lucheng(Js js, int n){
    return ssd + n *msd;
}

void init(Heap *h, int length_input) {
    h->data = (Js *)malloc(sizeof(Js) * length_input);
    h->size = 0;
}

void swap(Js *a, Js *b) {
    Js temp = *a;
    *a = *b;
    *b = temp;
}
int cmpnode(Js a, Js b,int n) {
    if (lucheng(a,n) < lucheng(b,n)) {return 1;}
    else return 0;
}

void push(Heap *h, Js js) {
    int n = 0;
    h->data[h->size] = js.bianhao;
    Js current = h->size;
    Js father = (current - 1) / 2;
    while (cmpnode(Js current, Js father,int n)) {
        swap(&h->data[current], &h->data[father]);
        current = father;
        father = (current - 1) / 2;
    }
    h->size++;
    n++;
}

int top(Heap *h) {
     return h->data[0];
}

void update(Heap *h, Js pos, int n) {
    int x = 0;
    int lchild = 2 * pos.bianhao + 1, rchild = 2 * pos.bianhao + 2;
    Js max_value = pos;
    if (lchild < n && cmpnode( lchild,  pos, x)) {
        max_value = lchild;
    }
    if (rchild < n && cmpnode( rchild,  pos, x)) {
        max_value = rchild;
    }
    if (max_value != pos) {
        swap(&h->data[pos], &h->data[max_value]);
        x++;
        update(h, max_value, n);
    }
}

void pop(Heap *h) {
    swap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    update(h, 0, h->size);
}

int heap_size(Heap *h) {
    return h->size;
}

void clear(Heap *h) {
    free(h->data);
    free(h);
}

void output(Heap *h) {
    for (int i = 0; i < h->size; i++) {
    printf("%d ",  h->data[i]);
    }
    printf("\n");
}

int main() {
    int t, n, tcase = 0;
    scanf("%d", &t);
    Heap *h[101];
    for (int i = 1; i <= 100; i++) {
        h[i] = (Heap *)malloc(sizeof(Heap));
        init_heap(h[i], 50000);
    }
    while (tcase < t) {
        printf("Case #%d:\n", ++tcase);
        scanf("%d", &n);
        Node zombie;
        int s;
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &zombie.f, &s);
            zombie.ind = i + 1;
            push_heap(h[s], zombie);
        }
        for (int i = 0; i < n; i++) {
            int m = -1;
            Node zombie1, zombie2;
            for (int j = 1; j <= 100; j++) {
                if (empty_heap(h[j])) continue;
                if (m == -1) {
                    m = j;
                    continue;
                }
                zombie1 = top_heap(h[m]);
                zombie2 = top_heap(h[j]);
                zombie1.f = zombie1.f + i * m;
                zombie2.f = zombie2.f + i * j;
                if (cmp_node(zombie2, zombie1)) {
                    m = j;
                }
            }
            printf("%d", top_heap(h[m]).ind);
            pop_heap(h[m]);
            if (i != n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = 1; i <= 100; i++) {
        clear_heap(h[i]);
    }
    return 0;
}
