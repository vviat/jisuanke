#include <stdio.h>
int binary_search(int target, int *num, int len) {
	int left, right, mid;
    left = 0; right = len - 1;
    while (left <= right) {
        mid = (left + right)  / 2;
        if (num[mid] == target) return mid;
        num[mid] < target ? left = mid + 1 : (right = mid - 1);
    }
    return -1;
}
int main() {
	int num[1000000];
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int value;
		scanf("%d", &value);
		printf("%d\n", binary_search(value, num, n));
	}
	return 0;
}
