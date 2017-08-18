#include <vector>
#include <iterator>
#include <cstdio>

//保存两个指针，一个指向0，一个指向非0。然后交换，接着从当前位置开始继续遍历找到下一个指向的值。
using namespace std;

void moveZeroes(vector<int> &nums) {
  vector<int>::iterator zero_pos = nums.begin();
  // 找到第一个0的位置
  while (zero_pos != nums.cend() && *zero_pos != 0) ++zero_pos;
  if (zero_pos == nums.cend()) return;
  // 找到第一个0后面的第一个非0位置
  vector<int>::iterator swap_pos = zero_pos + 1;
  while (swap_pos != nums.cend() && *swap_pos == 0) ++swap_pos;
  if (swap_pos == nums.cend()) return;
  for (; zero_pos != nums.cend(); ++zero_pos) {
    if (*zero_pos != 0) ++zero_pos;
    swap(*zero_pos, *swap_pos);
    while (swap_pos != nums.cend() && *swap_pos == 0) ++swap_pos;
    if (swap_pos == nums.cend()) break;
  }
}

int main() {
  vector<int> vec { -1,2,-3,4,0,1,0,-2,0,0,1 };
  moveZeroes(vec);
  for (int item : vec)
    printf("%d ", item);
  return 0;
}

