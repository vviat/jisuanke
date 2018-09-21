#include <stdio.h>
int gcd(int n, int m);
int lcm(int n, int m);
int main() {
    int n, m;
    scanf("%d%d", &n, &m);  
    printf("%d\n", gcd(n, m));
    printf("%d\n", lcm(n, m));
    return 0;
}
int gcd(int n, int m) {
    if (m < n) {
    // 请在这里继续完成 gcd 函数
        return gcd(m,n);
    } else if(m%n==0){
        return n;
    } else {
        return gcd(n, m%n);
    }
}
int lcm(int n, int m) {
// 请在这里继续完成 lcm 函数
return m*n/gcd(n,m);
}
