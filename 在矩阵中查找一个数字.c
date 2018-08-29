#include <stdio.h>
#include <stdlib.h>
int find_target(int ** matrix, int n, int m, int target) {
	int i = 0,j = m -1;
    while(i < n && j >= 0) {
        if(matrix[i][j] > target) {
            j--;
        } else if(matrix[i][j] < target) {
            i++;
        } else {
            return 1;
        }
    }
    return 0;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int ** v;
	v = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < m; ++i) {
		v[i] = (int*)malloc(m * sizeof(int));
	}
	int tp;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j){
			scanf("%d", &v[i][j]);
		}
	}
	int tot;
	scanf("%d", &tot);
	for (int i = 0; i < tot; ++i) {
		scanf("%d", &tp);
		if (find_target(v, n, m, tp)) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}
