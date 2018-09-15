#include <stdio.h>
#include<math.h>
int main() {
double a;
    double b;
    double c;
    scanf("%lf %lf",&a,&b);
    c=sqrt(a*a+b*b);
printf("%.2f\n",a+b+c);
    printf("%.2f",(a*b)/2);
    return 0;
}
