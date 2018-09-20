#include <stdio.h>
void upper_case_count(char arr[31]) {
    // 请在下面实现统计并输出大写字母个数的功能
    int j=0;
    for(int i = 0; i < 31; i++) {
        if(arr[i]>='A'&& arr[i]<='Z'){
         j++; 
            //printf("%c",&arr[i]);
        }
    }
    printf("%d\n",j);
}
void lower_case_count(char arr[31]) {
    // 请在下面实现统计并输出小写字母个数的功能
    int j=0;
    for(int i = 0; i < 31; i++) {
        if(arr[i]>='a'&& arr[i]<='z'){
            j++;
        }
    }
    printf("%d\n",j);
}
void digit_count(char arr[31]) {
    // 请在下面实现统计并输出数字个数的功能
    int j=0;
    for(int i = 0; i < 31; i++) {
        if(arr[i]>='0' && arr[i]<='9'){
            j++;
        }
    }
    printf("%d\n",j);
}
void space_count(char arr[31]) {
    // 请在下面实现统计并输出空格个数的功能
    int j=0;
    for(int i = 0; i < 31; i++) {
        if(arr[i]==32){
            j++;
        }
    }
    printf("%d\n",j);
}

int main() {
    char string[31];
    int i;
    for( i = 0; i < 31; i++) {
        scanf("%c",&string[i]);
    }
    
    upper_case_count(string);
    lower_case_count(string);
    digit_count(string);
    space_count(string);
    return 0;
    
}

