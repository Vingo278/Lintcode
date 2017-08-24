#include <vector>
#include <stack>
#include <iostream>

#include <climits>

using namespace std;

// 为了找到子串满足i<j<k,ai<ak<aj，我们维持着一个最大的ak，然后只要满足有一个小于ai的值
// 就找到了一个满足132的子串了。
// 利用栈，从右遍历。
// 当前元素如果比栈顶大，则出栈，然后当前元素入栈，则会发现出栈的数小于栈顶
// 所以出栈的数，就是我们ak。
// 当然为了保证ak是最大的，对于每个元素我们需要这样处理：
// 1. 如果小于ak则，满足132的子串。
// 2. 如果大于栈顶，则栈顶出元素，出到栈顶大于当前数。
// 3. 其他情况，入栈。保证了一件事。栈里面的数必定是比ak大的逆序。这就是为什么2出栈要出到
// 大于当前的数，那个数就是ak
bool find132pattern(vector<int>& nums) {
  if (nums.size() < 3) return false;
  int ak = INT_MIN;
  stack<int> st;
  vector<int>::iterator iter = nums.end() - 1;
  st.push(*iter);
  while(--iter >= nums.cbegin()) {
    if (*iter < ak) {
      return true;
    }
    while (!st.empty() && *iter > st.top()) {
      ak = st.top();
      st.pop();
    }
    st.push(*iter);
  }
  return false;
}

int main() {
  vector<int> vec {3, 1, 4, 2};
  vector<int> vec2 {1, 2, 3, 4};
  cout << find132pattern(vec) << endl;
  cout << find132pattern(vec2) << endl;
  return 0;
}
