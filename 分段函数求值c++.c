#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
    int x;
    int y;
    // 从用户处获得输入值 x
    cout << "请输入 x 的值：" << endl;
    cin >> x;

    // 在下面完成你的逻辑
if (x >= 0){
    y=1;
} else {
    y=-1;
}

    // 接下来的部分会输出 y 的结果
    cout << "y = " << y << endl;

    return 0;
}
