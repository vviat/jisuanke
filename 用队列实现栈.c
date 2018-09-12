#include <iostream>
#include <queue>
#include <string>
#include <utility>
using std::queue;
using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace std {

template<class T>
class stack {
 private:
    queue<T> queue1, queue2;
 public:
    stack(): queue1(), queue2() {}
    bool empty();
    T top();
    size_t size();
    void push(T &val);
    void pop();
};
/**
 * stack 的结构
 * template<class T>
 * class stack {
 *  private:
 *     queue<T> queue1, queue2;
 *  public:
 *     stack(): queue1(), queue2() {}
 *     bool empty();
 *     T top();
 *     size_t size();
 *     void push(T &val);
 *     void pop();
 * };
 */
template<class T>

bool stack<T>::empty() {
    return queue1.empty();
}
template<class T>
T stack<T>::top() {
    T ans, temp;
    while (!queue1.empty()) {
        temp = queue1.front();
        queue1.pop();
        queue2.push(temp);
    }
    ans = temp;
    while (!queue2.empty()) {
        temp = queue2.front();
        queue2.pop();
        queue1.push(temp);
    }
    return ans;
}
template<class T>
size_t stack<T>::size() {
    return queue1.size();
}
template<class T>
void stack<T>::push(T &val) {
    queue1.push(val);
}
template<class T>
void stack<T>::pop() {
    T ans, temp;
    if (queue1.empty()) return ;
    temp = queue1.front();
    queue1.pop();
    while (!queue1.empty()) {
        queue2.push(temp);
        temp = queue1.front();
        queue1.pop();
    }
    ans = temp;
    while (!queue2.empty()) {
        temp = queue2.front();
        queue2.pop();
        queue1.push(temp);
    }
    return ;
}

}
int main() {
    using std::stack;
    stack<std::pair<int, int> > point;
    int n;
    cin >> n;
    while (n--) {
        string op;
        cin >> op;
        if (op == "empty") {
            cout << (point.empty()?"true":"false") << endl;
        } else if (op == "top") {
            if (point.empty()) {
                cout << "error: stack is empty" << endl;
            } else {
                std::pair<int, int> top = point.top();
                cout << top.first << " " << top.second << endl;
            }
        } else if (op == "size") {
            cout << point.size() << endl;
        } else if (op == "push") {
            int x, y;
            cin >> x >> y;
            std::pair<int, int> temp(x, y);
            point.push(temp);
        } else if (op == "pop") {
            if (point.empty()) {
                cout << "error: stack is empty" << endl;
            } else {
                point.pop();
            }
        }
    }
    return 0;
}
