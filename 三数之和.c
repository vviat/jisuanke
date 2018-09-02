#include <stdio.h>
#include <stdlib.h>
int* three_sum(int *nums, int length, int target) {
    int *ans = malloc(sizeof(int) * 3);
    int i, l, r;
    int sum = 0;
    for (i = 0; i < length - 2; i++) {
        l = i + 1;
        r = length - 1;
        sum = nums[i] + nums[l] + nums[r];
        while (sum != target && l < r) {
            if (sum < target) {
                sum = sum - nums[l] + nums[l + 1];
                ++l;
            } else {
                sum = sum - nums[r] + nums[r - 1];
                --r;
            }
        }
        if (l < r) break;
    }
    ans[0] = i;
    ans[1] = l;
    ans[2] = r;
    return ans;
}
int main() {
    int n, target;
    scanf("%d %d", &n, &target);
    int* num = (int*)malloc(n * sizeof(int));
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", num + i);
        a[i] = num[i];
    }
    int *x = three_sum(num, n, target);
    int *p = three_sum(num, n, target);
    if (p[0] == p[1] || p[0] == p[2] || p[1] == p[2] ) {
        printf("一个数只能用一次!\n");
    } else {
        printf("%d\n", a[p[0]] + a[p[1]] + a[p[2]]);
    }
    free(p);
    free(num);
    free(a);
    return 0;
}
