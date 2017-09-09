#include <vector>
#include <algorithm>

using namespace std;

/*
 * 对于每一个位置上，能接多少水，决定向两边扩展的最大高度的最小值。
 * 如果每在一个位置上，都进行一次遍历，时间复杂度会很高，
 * 我们可以通过一次遍历，直接记录下左右的最大高度。
 * @param heights: a list of integers
 * @return: a integer
 */
int trapRainWater(vector<int> &heights) {
  if (heights.size() <= 2) return 0;
  vector<int> left(heights.size(), 0);
  // 0和size()-1的下标是不能存水，不用保存
  int max = heights[0];
  for (int i = 0; i < heights.size() - 1; ++i) {
    left[i] = max;
    if (heights[i] > max)
      max = heights[i];
  }
  int volume = 0;
  // right数组不用保存了，得出结果直接计算
  int right = heights[heights.size() - 1];
  for (int i = heights.size() - 1; i > 0 ; --i) {
    // 计算接水量
    int min_height = min(right, left[i]);
    if (min_height > heights[i])
      volume += (min_height - heights[i]);
    // 更新右边最大值
    if (heights[i] > right)
      right = heights[i];
  }
  return volume;
}
