#include <stdio.h>
int main() {
int n;
int a;
int i;
scanf("%d", &n);
for (i = n; i >=  1; i--) {
    for (a = n; a >=  n-i+1; a--) {

        if(a == n-i+1)
            printf("%d", i - (n - a));
        if(a != n-i+1){
            printf("%d ",i - (n - a));
            }
        }
        printf("\n");
}

    return 0;
}


