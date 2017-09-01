#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

// 数组A排序好，遍历数组B，通过二分搜索判断B的元素是否在A中；需要去重
/*
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  vector<int> result;
  sort(nums1.begin(), nums1.end());
  for (auto iter = nums2.begin(); iter != nums2.cend(); ++iter) {
    if (binary_search(nums1.cbegin(), nums1.cend(), *iter)) {
      result.push_back(*iter);
    }
  }
  sort(result.begin(), result.end());
  auto start = unique(result.begin(), result.end());
  result.erase(start, result.end());
  return result;
}
*/

// 遍历数组A做hash，遍历数组B判断是否hash过即可，遍历时对哈希表加1就可以去重
/*
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  vector<int> result;
  unordered_map<int, int> hash_table;
  for (auto iter = nums1.begin(); iter != nums1.cend(); ++iter) {
    hash_table[*iter] = 0;
  }
  for (auto iter = nums2.begin(); iter != nums2.cend(); ++iter) {
    if (hash_table.find(*iter) != hash_table.cend() && hash_table[*iter] == 0) {
      result.push_back(*iter);
      hash_table[*iter]++;
    }
  }
  return result;
}
*/

// 两数组排序，两数组从小到大遍历，保持同步，即可判断
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  vector<int> result;
  sort(nums1.begin(), nums1.end());
  sort(nums2.begin(), nums2.end());
  for (auto iter1 = nums1.begin(), iter2 = nums2.begin();
      iter1 != nums1.cend() && iter2 != nums2.cend(); ) {
    if (*iter1 < *iter2) {
      ++iter1;
    } else if (*iter1 > *iter2) {
      ++iter2;
    } else {
      // 因为是排序好的，所以只需要和上一个需要插入的值是否一样，就可以去重
      // 或的第二个参数，不用判断空，因为空的话就会插入了
      if (result.empty() || *iter1 != *(result.end() - 1)) {
        result.push_back(*iter1);
      }
      ++iter1;
      ++iter2;
    }
  }
  return result;
}
