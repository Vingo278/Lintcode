#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int dfs(int n, string& str, int idx, vector<bool> used) {
  // 遍历完字符串
  if (idx == str.size()) {
    vector<int> result;
    for (int i = 1; i < used.size(); ++i) {
      if (!used[i]) result.push_back(i);
    }
    if (result.size() == 1)
      return result[0];
    else
      return -1;
  }
  // 该题不包含数字0
  if (str[idx] == '0') return -1;
  // 数字最大30只需要搜索2位
  for (int i = 1; i <= 2; ++i) {
    int num = static_cast<int>(strtoul(str.substr(idx, i).c_str(), NULL, 10));
    if (num <= n && !used[num]) {
      used[num] = true;
      int ret = dfs(n, str, idx + i, used);
      if (ret != -1)
        return ret;
      used[num] = false;
    }
  }
  return -1;
}

/*
 * 这道题在于我们需要从字符串里面选取子串来作为数字，当我们选取的子串过长而正确时需要回溯，
 * 可以用深度搜索
 * @param n: An integer
 * @param str: a string with number from 1-n in random order and miss one number
 * @return: An integer
 */
int findMissing2(int n, string &str) {
  vector<bool> used(n + 1, false);
  return dfs(n, str, 0, used);
}
