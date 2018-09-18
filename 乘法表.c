#include <stdio.h>
int main() {
int n;
int a;
int i;
scanf("%d", &n);
for (i = 1; i <= n; i++) {
    for (a = 1; a <= n-i+1; a++) {

        if(a == n-i+1)
            printf("%d*%d=%d",i,i + a - 1,i * (i + a - 1) );
        if(a != n-i+1){
            printf("%d*%d=%d\t",i,i + a - 1,i * (i + a - 1) );
            }
        }
        printf("\n");
}

    return 0;
}

