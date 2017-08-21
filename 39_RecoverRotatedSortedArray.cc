#include <vector>
#include <cstdio>
#include <iterator>

using namespace std;
// 找到最小值，为界限，分为前部分和后部分，对两部分进行反转就是一个逆序的数组，再反转一次
// 简单，不用STL实现了
void reverse(vector<int>::iterator begin, vector<int>::iterator end) {
  while (begin < end) {
    end--;
    swap(*begin, *end);
    begin++;
  }
}

vector<int>::iterator findMin(vector<int> &vec) {
  if (vec.size() <= 1) return vec.begin();
  vector<int>::iterator min = vec.begin();
  vector<int>::iterator iter;
  for (iter = vec.begin() + 1; iter < vec.cend(); ++iter) {
    if (*iter < *min) {
      min = iter;
    }
  }  
  return min;
}

void recoverRotatedSortedArray(vector<int> &nums) {
  auto min_pos = findMin(nums);
  reverse(nums.begin(), min_pos);
  reverse(min_pos, nums.end());
  reverse(nums.begin(), nums.end());
}

int main() {
  vector<int> vec { 5, 6, 7, 8, 9, 1, 2, 3, 4 };
  recoverRotatedSortedArray(vec);
  for (int value : vec) {
    printf("%d ", value);
  }
  return 0;
}
