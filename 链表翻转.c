#include <string.h>
#include <stdio.h>
#define bool int
#define false 0
#define true 1
/** 
 * 预先的宏定义
 * #define bool int
 * #define false 0
 * #define true 1
 */
bool weak_equivalent(char *str1, int length1,
                     char *str2, int length2) {
    if (length1 != length2) return 0;
    if (strncmp(str1, str2, length1) == 0) return 1;
    if (length1 % 2) return 0;
    int mid = length1 / 2, i;
    bool flag[4];
    int letter_nums[4][26] = {0};
    for (i = 0; i < mid; ++i) {
        letter_nums[0][str1[i] - 'a']++;
        letter_nums[1][str1[i + mid] - 'a']++;
        letter_nums[2][str2[i] - 'a']++;
        letter_nums[3][str2[i + mid] - 'a']++;
    }
    char *first, *second;
    for (i = 0; i < 4; ++i) {
        first = str1 + (i / 2) * mid;
        second = str2 + (i % 2) * mid;
        if (strncmp(letter_nums[i/2], letter_nums[i % 2 + 2], 26) == 0) {
            flag[i] = weak_equivalent(first, mid, second, mid);
        } else {
            flag[i] = false;
        }
    }
    return ((flag[0] && flag[3]) || (flag[1] && flag[2]));
}
#define BUFFSIZE 50010
char s1[BUFFSIZE], s2[BUFFSIZE];
int main() {
    scanf("%s", s1);
    scanf("%s", s2);
    if (weak_equivalent(s1, (int)strlen(s1), s2, (int)strlen(s2))) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}
