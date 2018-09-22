// #include <stdio.h>
// #include<string.h>
// int main() {
//     int n;
//     scanf("%d", &n);
//     char a[500];
//     char b[500];
//     int i,k=0;
//     int tmp = 0;
//     for (i = 0; i<n; i++) {
//         while (scanf("%c",&a[k])) {
//             if(a[k+1]=='\n') {
//                 a[k+1]='\0';
//                 break;
//             }        
//         }   
//         if(strlen(a)>tmp) {
//             strcpy(b,a);
//             tmp = strlen(a);
//         }
//     }
//     printf("%s\n",b);
//     return 0;
// }


#include <stdio.h>
#include <string.h>
int main() {
    int i, n, len, j;
    scanf("%d\n", &n);
    char str[101], longest_name[101];
    len = 0;
    for (i = 0; i < n; ++i) {
        j = 0;
        while (scanf("%c", &str[j])) {
            if (str[j++] == '\n') {
                str[j-1] = '\0';
                break;
            }
        }
        if (strlen(str) > len) {
            strcpy(longest_name, str);
            len = strlen(str);
        }
    }
    printf("%s\n", longest_name);
    return 0;
}
