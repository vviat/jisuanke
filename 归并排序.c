#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void merge_sort(int *nums, int left, int right) {
    // int mid = (l + r) >> 1;
    // merge_sort(nums,l,mid);
    // merge_sort(nums,mid+1,r);
    // int *temp = (int *)malloc(sizeof(int ) * (r-l+1));
    // int p1 = l, p2 = mid + 1, k = 0;
    // while(p1 <= mid || p2 <= r){
    //     if((p2 > r) || (p1 <= mid && nums[p1] <= nums[p2])){
    //         temp[k++] = nums[p1++];
    //     } else {
    //         temp[k++] = nums[p2++];
    //     }
    // }
    // memcpy(nums + l, temp, sizeof(int) * (r - l + 1));
    // free(temp);
    // return ;
    if (right == left) return ;
    int *arr = (int *)malloc((right - left + 1) * sizeof(int));
    int ind1[2], ind2[2];
    ind1[0] = left;
    ind1[1] = ind1[0] + (right - left + 1) / 2 - 1;
    ind2[0] = ind1[1] + 1;
    ind2[1] = right;
    merge_sort(nums, ind1[0], ind1[1]);
    merge_sort(nums, ind2[0], ind2[1]);
    int j = 0;
    while (ind1[0] <= ind1[1] || ind2[0] <= ind2[1]) {
        if (ind1[0] > ind1[1]) {
            arr[j++] = nums[ind2[0]++];
        } else if (ind2[0] > ind2[1]) {
            arr[j++] = nums[ind1[0]++];
        } else {
            arr[j++] = (nums[ind1[0]] < nums[ind2[0]] ? nums[ind1[0]++] : nums[ind2[0]++]);
        }
    }
    memcpy(nums + left, arr, (right - left + 1) * sizeof(int));
    free(arr);
}
int main() {
    int n;
    scanf("%d", &n);
    int *num = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", num + i);
    }
    merge_sort(num, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        printf("%d%c", num[i], i == n - 1? '\n' : ' ');
    }
    free(num);
    return 0;
}

