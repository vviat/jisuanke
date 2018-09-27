#include <iostream>
#include <iomanip>
#include<cmath>
using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;
using std::showpoint;
int main() {
double a;
    double b;
    double c;
    cin>>a>>b;
    c = sqrt(a*a+b*b);
    cout<<showpoint;
    cout<<fixed;
    cout<<setprecision(2);
    cout<<a+b+c<<endl;
    cout<<(a*b)/2.0<<endl;

    return 0;
}
