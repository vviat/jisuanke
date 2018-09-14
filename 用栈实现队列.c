#include <iostream>
#include <stack>
#include <string>
#include <utility>
using std::stack;
using std::cin;
using std::cout;
using std::endl;
using std::string;

namespace std {

template<class T>
class queue {
 private:
    stack<T> stack1, stack2;
 public:
    queue(): stack1(), stack2() {}
    bool empty();
    T front();
    size_t size();
    void push(T &val);
    void pop();
};
/**
 * queue 的结构
 * template<class T>
 * class queue {
 *  private:
 *     stack<T> stack1, stack2;
 *  public:
 *     queue(): stack1(), stack2() {}
 *     bool empty();
 *     T front();
 *     size_t size();
 *     void push(T &val);
 *     void pop();
 * };
 */

template<class T>
bool queue<T>::empty() {
    return stack1.empty() && stack2.empty();
}
template<class T>
T queue<T>::front() {
    if (stack2.empty()) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    return stack2.top();
}
template<class T>
size_t queue<T>::size() {
    return stack1.size() + stack2.size();
}
template<class T>
void queue<T>::push(T &val) {
    stack1.push(val);
}
template<class T>
void queue<T>::pop() {
    this->front();
    stack2.pop();
}

}
int main() {
    using std::queue;
    queue<std::pair<int, int> > point;
    int n;
    cin >> n;
    while (n--) {
        string op;
        cin >> op;
        if (op == "empty") {
            cout << (point.empty()?"true":"false") << endl;
        } else if (op == "front") {
            if (point.empty()) {
                cout << "error: queue is empty" << endl;
            } else {
                std::pair<int, int> front = point.front();
                cout << front.first << " " << front.second << endl;
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
                cout << "error: queue is empty" << endl;
            } else {
                point.pop();
            }
        }
    }
    return 0;
}
