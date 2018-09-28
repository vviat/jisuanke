#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
    int year;
    // 从用户处获得一个不大于 3000 的年份
    cin>>year;

    // 在下面完成你的逻辑
if((year % 100 != 0 && year %4 == 0) || year % 400 == 0) {
    cout<<"YES";
} else {
    cout<<"NO";
}

    return 0;
}
