#include <stdio.h>
int main() {
int n;
int a;
int i;
scanf("%d", &n);
for (i = 1; i <=  n; i++) {
    for(a = 1; a <=  n; a++) {
        if(a==n)
            printf("%d", i);
        if(a!=n){
            printf("%d ",i);
        }
        }
        printf("\n");
}

    return 0;
}

