#include <string>
#include <algorithm>

using namespace std;

/*
 * 遍历，维护一个左边界，和目前子串字符数，和已有字符的hash表
 * @param s: A string
 * @param k: An integer
 * @return: An integer
 */
int lengthOfLongestSubstringKDistinct(string &s, int k) {
  // k可能大于size
  if (s.size() < k) return s.size();
  int left = 0;  // 左边界
  int distinct = 0;  // 字符数
  int hash[256] = {0};
  int max_len = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (!hash[s[i]])
      ++distinct;
    ++hash[s[i]];
    if (distinct <= k)
      max_len = max(max_len, i - left + 1);
    while (distinct > k) {
      if (--hash[s[left]] == 0)
        distinct--;
      ++left;
    }
  }
  return max_len;
}
