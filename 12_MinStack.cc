#include <stack>
#include <iostream>

using namespace std;

// 这题的关键在于如何在栈中取到最小值。
// 我们只需要在每次入栈的时候保存对应于当前栈中的最小值即可。
// 由于栈只能pop，所以弹出栈后，不会影响之前保存的值。
// 会发现对最小值刚好可以用栈来实现，push对应push，pop对应pop
// min对应top
class MinStack {
 public:
  MinStack() {
  }
  void push(int number) {
    nor_stack_.push(number);
    // 保存最小值的栈在每次压栈前都需要比较
    if (!min_stack_.empty()) {
      int top = min_stack_.top();
      min_stack_.push(number < top ? number : top);
    } else {
      min_stack_.push(number);
    }
  }
  int pop() {
    int ret = nor_stack_.top();
    nor_stack_.pop();
    min_stack_.pop();
    return ret;
  }
  int min() {
    return min_stack_.top();
  }
 private:
  stack<int> nor_stack_;
  stack<int> min_stack_;
};
