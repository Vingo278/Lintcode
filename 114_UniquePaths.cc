#include <cstdio>
#include <algorithm>

// 简单的动态规划题，记点的坐标为(i, j)，则到达当前点的路径数
// paths(i, j) = paths(i, j - 1) + paths(i - 1, j)
// 遍历所有点然后打表就可以了。
// 由于并不需要用到整张表，只需要用到上一行。
// 所以用两个数组交替，可以降低空间复杂度。
int uniquePaths(int m, int n) {
  // 利用两个数组交替，代替m*n的表，降低空间复杂度
  int *fronts = new int [n];
  int *curs = new int [n];
  // 第一行特殊情况
  for (int i = 0; i < n; ++i) fronts[i] = 1;
  while (--m > 0) {
    // 第一列特殊情况
    curs[0] = 1;
    for (int i = 1; i < n; ++i) {
      curs[i] = curs[i - 1] + fronts[i];
    }
    std::swap(fronts, curs);
    for (int i = 0; i < n; ++i) printf("%d ", fronts[i]);
    printf("\n");
  }
  int ret = fronts[n - 1];
  delete [] fronts;
  delete [] curs;
  return ret;
}

int main() {
  int m = 5;
  int n = 58;
  printf("%d, %d: %d\n", m, n, uniquePaths(m, n));
  return 0;
}
