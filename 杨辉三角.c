#include <stdio.h>
long long PascalTriangle(int row, int column) {
    long long *arr = (long long *)calloc(row, sizeof(long long));
	arr[0] = 1;
    for(int i = 1; i < row; i++) {
        for(int j = i; j > 0; j--){
            arr[j] += arr[j - 1];
        }
    }
    long long ret = arr[column - 1];
    free(arr);
    return ret;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%lld\n", PascalTriangle(n, m));
	return 0;
}
