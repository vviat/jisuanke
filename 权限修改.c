#include <stdio.h>
int getv(char c);

int main() {
    int i;
    char str[5]={0};
    int len;
    int v = 0;//值
    scanf("%s",str);
    len = strlen(str);
    for (i = 0; i < len; i++) {
        v = v | getv(str[i]);
    }

    while (scanf("%s",str) !=EOF) {
        if (str[0]=='+')
            v=v | getv(str[1]);
        else if (str[0]=='-')
            v=v & (~getv(str[1]));
        else printf("格式错误　，重来");
    }
    printf("%d\n",v);
    return 0;
}




int getv(char c){
    switch(c){
        case 'r' : return 4;
        case 'w' : return 2;
        case 'x' : return 1;
        default : printf("输入错误\n");
    }
    return 0;
}
