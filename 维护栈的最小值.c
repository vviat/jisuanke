#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    int *arr;
    int top, max_len;
} Stack;


int initStack(Stack *s) {
    int bsize = 30;
    s->arr = (int *)malloc(bsize * sizeof(int));
    s->max_len = bsize;
    s->top = 0;
    return 1;
}

int pushStack(Stack *s, int a) {
    if (s->arr == NULL) return 0;
    if (s->top == s->max_len) {
        s->arr = (int *)realloc(s->arr, s->max_len * 2 * sizeof(int));
        if (s->arr == NULL) return 0;
        s->max_len *= 2;
    }
    s->arr[s->top++] = a;
    return 1;
}

int emptyStack(Stack *s) {
    return !(s->top);
}

int popStack(Stack *s) {
    if (!emptyStack(s)) {
        --(s->top);
        return s->arr[s->top];
    }
    return 0;
}
 
int seekStack(Stack *s) {
    if (!emptyStack(s)) {
        return s->arr[s->top - 1];
    }
    return 0;
}

int* stackMinimumValues(char **operation, int *value, int length) {
    int *ans = malloc(sizeof(int) * length);
    Stack main_stack;
    Stack min_stack;
    initStack(&main_stack);
    initStack(&min_stack);
    int i;
    for (i = 0; i < length; ++i) {
        switch (operation[i][2]) {
            case 's' :
                pushStack(&main_stack, value[i]);
                if (emptyStack(&min_stack) || seekStack(&min_stack) >= value[i]) {
                    pushStack(&min_stack, value[i]);
                }
                ans[i] = seekStack(&min_stack);
                break;
            case 'p' :
                if (popStack(&main_stack) == seekStack(&min_stack)) {
                    popStack(&min_stack);
                }
                ans[i] = seekStack(&min_stack);
                break;
            default :
                printf("ERROR\n");
                break;
        }
    }
    return ans;
}
int main() {
    int n;
    scanf("%d", &n);
    char **op = (char**)malloc(n * sizeof(char*));
    int *value = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        char ss[5];
        scanf("%s %d", ss, value + i);
        op[i] = strdup(ss);
    }
    int *res = stackMinimumValues(op, value, n);
    for (int i = 0; i < n; ++i) {
        printf("%d ", res[i]);
    }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        free(op[i]);
    }
    free(value);
    return 0;
}
