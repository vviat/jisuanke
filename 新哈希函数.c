#include <stdio.h>
int main() {
    char str[1000];
    int arr[32] = {0};
    int bits[32] = {0};
    int len,i,j;
    scanf("%s", str);
    len = strlen(str);
    for (i = 1; i <= len; i++) {
        arr[i % 32] += str[i - 1];
    }
    for (j = 0; j < 32; j++) {
        bits[j] = arr[31 - j] ^ (arr[j] << 1);
        printf("%c", bits[j] % 85 + 34);
    }
    return 0;
}
