#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void quick_sort(int *nums, int left, int right) {
    int x, y, z;
    while (left < right) {
        z = nums[left];
        x = left; y = right;
        while (x < y) {
            while (x < y && nums[y] < z) --y;
            if (x < y) nums[x++] = nums[y];
            while (x < y && nums[x] > z) ++x;
            if (x < y) nums[y--] = nums[x];
        }
        nums[x] = z;
        quick_sort(nums, x + 1, right);
        right = x - 1;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int *num = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", num + i);
    }
    quick_sort(num, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        printf("%d%c", num[i], i == n - 1? '\n' : ' ');
    }
    free(num);
    return 0;
}

