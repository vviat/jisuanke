#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    int first, second;
} Pair;
/** Pair 的定义如下
 * typedef struct {
 *     int first, second;
 * } Pair;
 */
typedef struct {
    int *arr;
    int top, len;
} Stack;

int emptyStack(Stack *s) {
    return (s->top == s->len);
}

int initStack(Stack *s, int size) {
    s->arr = (int *)malloc(size * sizeof(int));
    if (s->arr == NULL) return 0;
    s->len = size;
    s->top = size;
    return 1;
}
 
int pushStack(Stack *s, int a) {
    if (s->top <= 0) return 0;
    --(s->top);
    s->arr[s->top] = a;
    return 1;
}
 
int seekStack(Stack *s) {
    if (!emptyStack(s)) {
        return s->arr[s->top];
    }
    return -1;
}
 
int popStack(Stack *s) {
    if (!emptyStack(s)) {
        ++(s->top);
        return s->arr[s->top - 1];
    }
    return -1;
}
 
 
int destroyStack(Stack *s) {
    s->top = s->len = 0;
    free(s->arr);
    s->arr = NULL;
    return 1;
}
 
Pair* bracketsPairs(char *str) {
    int len = strlen(str);
    if (len % 2) return NULL;
    Pair *ret = (Pair *)malloc(len / 2 * sizeof(Pair));
    Stack s;
    int ind = 1, retind = 0;
    int flag = 1;
    initStack(&s, len / 2);
    while (str[ind - 1] && flag) {
        switch (str[ind - 1]) {
            case '(':
                pushStack(&s, ind);
                break;
            case ')':
                if (emptyStack(&s)) {
                    flag = 0;
                    break;
                }
                ret[retind].first = popStack(&s);
                ret[retind].second = ind;
                ++retind;
                break;
            default : break;
        }
        ++ind;
    }
    destroyStack(&s);
    if (flag == 0) {
        free(ret);
        return NULL;
    }
    return ret;
}
 

int main() {
    char str[50010];
    scanf("%s", str);
    Pair* result = bracketsPairs(str);
    if (!result) {
        puts("No");
    } else {
        puts("Yes");
        for (int i = 0; i < strlen(str) / 2; ++i) {
            printf("%d %d\n", result[i].first, result[i].second);
        }
        free(result);
    }
    return 0;
}
