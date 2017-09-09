#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * 我们只需要把数组分成两个部分，小的负数放在偶数下标，大的放在奇数下标即可
 * 这样就出现了一个问题，和中位数一样大的数，应该如何放呢？应该放两端
 * 其实是奇数的最大，偶数的最小上。
 * @param nums a list of integer
 * @return void
 */  
/*
void wiggleSort(vector<int>& nums) {
  auto mid_ptr = nums.begin() + nums.size() / 2;
  nth_element(nums.begin(), mid_ptr, nums.end());
  int mid = *mid_ptr;
  vector<int> result(nums.size(), 0);  // O(n)的空间复杂度
  int odd_idx = 1;
  int even_idx = nums.size() % 2 == 0 ? nums.size() - 2 : nums.size() - 1;
  for (auto iter = nums.begin(); iter != nums.cend(); ++iter) {
    if (*iter > mid) {
      result[odd_idx] = *iter;
      odd_idx += 2;
    } else if (*iter < mid) {
      result[even_idx] = *iter;
      even_idx -= 2;
    }
  }
  while (odd_idx <= static_cast<int>(nums.size()) - 1) {
    result[odd_idx] = mid;
    odd_idx += 2;
  }
  while (even_idx >= 0) {
    result[even_idx] = mid;
    even_idx -= 2;
  }
  nums = result;
}
*/

inline size_t NewIdx(size_t i, size_t n) {
  return (1 + 2 * i) % (n | 1);
}
/**
 * newIdx = (1 + i * 2) % (n | 1)
 * 就可以做到把映射后的下标：
 * 1. 前部分映射奇数坐标
 * 2. 后部分映射橙偶数坐标
 * 3. 和中位数相等的在奇偶的两端
 * 然后利用3-way-partition
 * @param nums a list of integer
 * @return void
 */ 
void wiggleSort(vector<int>& nums) {
  int n = nums.size();
  auto mid_ptr = nums.begin() + n / 2;
  nth_element(nums.begin(), mid_ptr, nums.end());
  int mid = *mid_ptr;
  int first_part = 0;
  int last_part = n - 1;
  int i = 0;
  while (i <= last_part) {
    int idx = NewIdx(i, n);
    if (nums[idx] > mid) {
      swap(nums[idx], nums[NewIdx(first_part++, n)]);
      ++i;
    } else if (nums[idx] < mid) {
      // 从后面swap过来的元素没进行过比较，不能增加i
      swap(nums[idx], nums[NewIdx(last_part--, n)]);
    } else {
      ++i;
    }
  }
}

int main() {
  vector<int> vec { 1, 5, 1, 1, 6, 4 };
  wiggleSort(vec);
  for (int val : vec) 
    cout << val << ' ';
  return 0;
}
