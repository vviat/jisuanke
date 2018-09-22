#include <stdio.h>

int main() {
    int matrix_a[10][10];
    int matrix_b[10][10];
    int m;
    int n;
    int i;
    int j;
    int sum ,k;
    scanf("%d%d", &m, &n);
    for(i=0;i<m;i++){
        for(j=0;j<n;j++) {
            scanf("%d",&matrix_a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++) {
            scanf("%d",&matrix_b[i][j]);
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            sum = 0;
            for (k = 0; k < n; k++) {
                sum += matrix_a[i][k] * matrix_b[k][j];
            }
            printf("%d", sum);
        if (j != m - 1) { 
            printf(" ");
        }
    }
        printf("\n");
 }
    return 0;
}
