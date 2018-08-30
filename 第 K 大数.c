#include <stdio.h>
#include <stdlib.h>
int __find_kth_number(int *num1, int *num2, int len1, int len2, int k) {
    if (len1 == 0) return num2[k - 1];
    if (len2 == 0) return num1[k - 1];
    if (k == 1) {
        return num1[0] < num2[0] ? num1[0] : num2[0];
    }
    int a1, b1;
    a1 = len1 < k / 2 ? len1 : k / 2;
    b1 = len2 < k - a1 ? len2 : k - a1;
    a1 = k - b1;
	if (num1[a1 - 1] < num2[b1 - 1]) {
    	return __find_kth_number(num1 + a1, num2, len1 - a1, len2, k- a1);
    } else {
    	return __find_kth_number(num1, num2 + b1, len1, len2 - b1, k - b1);    
    }
}

int find_kth_number(int *num1, int *num2, int n, int k) {
	return __find_kth_number(num1, num2, n, n, k);
}
int main() {
	int n;
	scanf("%d", &n);
	int *num1 = malloc(n * sizeof(int));
	int *num2 = malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i) {
		scanf("%d ", &num1[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d ", &num2[i]);
	}
	int m, tp;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &tp);
		printf("%d\n", find_kth_number(num1, num2, n, tp));
	}
	return 0;
}
