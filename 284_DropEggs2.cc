#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>

using namespace std;
// 记DropEggs(n, k)为n个鸡蛋，k层楼，最坏情况下需要扔的次数
// 假设再m层扔下第一个鸡蛋：
// 1. 碎了。总的次数为1 + DropEggs(n - 1, m - 1);
// 2. 没碎。总的次数为1 + DropEggs(n, k - m);
// 所以可以知道递推公式为DropEggs(n, k) = 1 + max(DropEggs(n-1, m-1), DropEggs(n, k-m))
// 遍历m，求最小值即可。
int dropEggs2(int n, int k) {
  // min_drop[i][j]表示i个鸡蛋，j层楼最少扔的个数
  // vector<vector<int>> min_drop(n + 1, vector<int>(k + 1));
  int **min_drop = new int*[n + 1];
  // 初始化0，1层楼的情况
  for (int i = 0; i <= n; ++i) {
    min_drop[i] = new int[k + 1];
    min_drop[i][0] = 0;
    min_drop[i][1] = 1;
  }
  // 一个鸡蛋，只能多少层扔多少次
  for (int j = 1; j <= k; ++j)
    min_drop[1][j] = j;
  // 自底向上，如果自上向底递归，需要min_drop移到这个函数外
  for (int i = 2; i <= n; ++i) {
    for (int j = 2; j <= k; ++j) {
      // 上面两个递归属于动态规划中打表，下面是我们上面讨论的遍历m
      min_drop[i][j] = INT_MAX;
      for (int m = 1; m <= j; ++m) {
        int drop_time = 1 + max(min_drop[i - 1][m - 1], min_drop[i][j - m]);
        min_drop[i][j] = min(min_drop[i][j], drop_time);
      }
    }
  }
  int ret = min_drop[n][k];
  for (int i = 0; i <= n; ++i) delete [] min_drop[i];
  delete [] min_drop;
  return ret;
}
