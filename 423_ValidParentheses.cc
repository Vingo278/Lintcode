#include <string>
#include <stack>
#include <iostream>

using namespace std;

// 用栈可以简单实现，只要最后栈是空的，即正确
bool isValidParentheses(string s) {
  stack<char> stk;
  for (int i = 0; i < s.size(); ++i) {
    switch (s[i]) {
      case '(':
      case '[':
      case '{':
        stk.push(s[i]);
        break;
      case ')':
        if (!stk.empty() && stk.top() != '(') return false;
        stk.pop();
        break;
      case ']':
        if (!stk.empty() && stk.top() != '[') return false;
        stk.pop();
        break;
      case '}':
        if (!stk.empty() && stk.top() != '{') return false;
        stk.pop();
        break;
      default:
        return false;
    }
  }
  if (stk.empty())
    return true;
  else
    return false;
}

