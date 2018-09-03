#include <stdio.h>
#include <stdlib.h>
int reverse_pairs(int *nums, int length) {
    if (length <= 1) return 0;
    int *arr = (int *)malloc(length * sizeof(int));
    int ans = 0;
    int len1, len2;
    int *arr1, *arr2;
    len1 = length / 2;
    len2 = length - len1;
    arr1 = nums;
    arr2 = nums + len1;
    ans += reverse_pairs(arr1, len1);
    ans += reverse_pairs(arr2, len2);
    int i, j, k;
    i = j = 0;
    while (i < len1 && j < len2) {
        while (i < len1 && arr1[i] <= 3 * arr2[j]) {
            ++i;
        }
        ans += (len1 - i);
        ++j;
    }
    i = j = k = 0;
    while (i < len1 || j < len2) {
        if (i == len1) {
            arr[k++] = arr2[j++];
        } else if (j == len2) {
            arr[k++] = arr1[i++];
        } else {
            arr[k++] = arr1[i] < arr2[j] ? arr1[i++] : arr2[j++];
        }
    }
    for (i = 0; i < length; ++i) {
        nums[i] = arr[i];
    }
    free(arr);
    return ans;
}
int main() {
    int n;
    scanf("%d", &n);
    int *num = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
    }
    printf("%d\n", reverse_pairs(num, n));
    return 0;
}
