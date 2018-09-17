#include <stdio.h>
#include<math.h>

long long fun(int b) {
    long long ans = 1, base = 2;
    while (b) {
    	if (b & 1) ans *= base;
        base *= base;
        b /= 2;
    }
    return ans;
}
long long paintWallCounts(int wallsize) {
    long long f[wallsize];
    f[1] = 3;
    f[2] = 6;
    for(int i = 3; i <= wallsize; i++) {
        f[i] = 3 * fun(i - 1) - f[i - 1];
    }
    return f[wallsize];
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", paintWallCounts(n));
    return 0;
}
