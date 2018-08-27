#include <stdio.h>
#include <string.h>
int find_first_capital_letter(char *str, int len) {
    int left, right, mid;
    left = 0; right = len - 1;
    while (left < right) {
        mid = (left + right)  / 2;
        str[mid] <= 'Z' && str[mid] >= 'A' ? right = mid : (left = mid + 1);
    }
    return left;
}
int main() {
    char str[100000+5];
    scanf("%s", str);
    int sum = 0;
    int len = strlen(str);
    for (int i = 0; i < 100000; ++i) {
        int x = find_first_capital_letter(str, len);
        sum += x;
    }
    printf("%d\n", find_first_capital_letter(str, len));
    return 0;
}
