#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 先通过二分查找，找出所在行，再对所在行进行二分查找。

// 二分查找，找到第一个小于等于的值
int BinarySearch(vector<vector<int>> matrix, int target) {
  int left = 0;
  int right = matrix.size() - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (target >= matrix[mid][0])
      left = mid + 1;
    else
      right = mid - 1;
  }
  return right;
}

bool searchMatrix(vector<vector<int>> matrix, int target) {
  int target_vector = BinarySearch(matrix, target);
  if (target_vector == -1) return false;
  return binary_search(matrix[target_vector].cbegin(),
      matrix[target_vector].cend(), target);
}

int main() {
  vector<vector<int>> matrix = {
    {1, 3, 5, 7},
    {10, 11, 16, 20},
    {23, 30, 34, 50}
  };
  cout << (searchMatrix(matrix, 2) ? "True" : "False") << endl;
  return 0;
}
