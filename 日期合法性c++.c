#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
 
bool leap_year(int y) {
    if (y % 4 == 0 && y % 100 != 0) return true;
    if (y % 400 == 0) return true;
    return false;
}
 
int main() {
    int y, m, d, max_day;
    char op;
    cin >> y >> op >> m >> op >> d;
    if (m > 12) {
        max_day = -1;
    } else if (m == 2) {
        max_day = (leap_year(y) ? 29 : 28);
    } else if (m <= 7) {
        max_day = ((m & 1) ? 31 : 30);
    } else {
        max_day = ((m & 1) ? 30 : 31);
    }
    cout << (d <= max_day ? "YES" : "NO") << endl;
    return 0;
}
