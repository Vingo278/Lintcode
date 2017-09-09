#include <vector>
#include <algorithm>

using namespace std;

/**
 * 注意该题和2的区别在于是否有等于号，因为有等于号的原因，所以任意两个相邻的数都可以比较。
 * 所以只需要遍历所有的数，把不符合的数交换即可
 * @param nums a list of integer
 * @return void
 */  
void wiggleSort(vector<int>& nums) {
  for (int i = 1; i < nums.size(); ++i) {
    if (i % 2 == 1) {
      if (nums[i] < nums[i - 1]) swap(nums[i], nums[i - 1]);
    } else {
      if (nums[i] > nums[i - 1]) swap(nums[i], nums[i - 1]);
    }
  }
}
