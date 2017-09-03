#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 547写了三种方法，其中方法效率不高，而且对题不好处理，所以只用后两种实现

// 用哈希表实现，对数组1，key值为元素个数。数组2对哈希表进行匹配，每次匹配减1即可。
/*
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  vector<int> result;
  unordered_map<int, int> hash;
  for (auto iter = nums1.begin(); iter != nums1.cend(); ++iter) {
    if (hash.find(*iter) != hash.cend())
      hash[*iter]++;
    else
      hash[*iter] = 1;
  }
  for (auto iter = nums2.begin(); iter != nums2.cend(); ++iter) {
    if (hash.find(*iter) != hash.cend() && hash[*iter] > 0) {
      result.push_back(*iter);
      hash[*iter]--;
    }
  }
  return result;
}
*/

// 对两数组排序后，遍历时，相等只跳过一个元素即可，不要跳过所有当前的值。
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  vector<int> result;
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
  for (auto iter1 = nums1.begin(), iter2 = nums2.begin();
      iter1 != nums1.cend() && iter2 != nums2.cend(); ) {
    if (*iter1 == *iter2) {
      result.push_back(*iter1);
      ++iter1;
      ++iter2;
    } else if (*iter1 < *iter2) {
      ++iter1;
    } else {
      ++iter2;
    }
  }
  return result;
}
