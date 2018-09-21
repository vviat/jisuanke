#include <stdio.h>

int main() {
    int a[3][3]={0};
    int i, j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    int b[2][2]={0};
    int n, m;
    for(n=0;n<2;n++){
        for(m=0;m<2;m++) {
            scanf("%d",&b[n][m]);
        }
    }
    int c=(a[0][0]*a[1][1]*a[2][2]+a[0][1]*a[1][2]*a[2][0]+a[0][2]*a[1][0]*a[2][1])-(a[0][2]*a[1][1]*a[2][0]+a[0][0]*a[1][2]*a[2][1]+a[0][1]*a[1][0]*a[2][2]);
    int d=b[0][0]*b[1][1]-b[0][1]*b[1][0];
    
    if(c>=d) printf("%d",c);
    else printf("%d",d);
    return 0;
}
