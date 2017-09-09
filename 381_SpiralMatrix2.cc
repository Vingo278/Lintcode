#include <vector>

using namespace std;

/**
 * @param n an integer
 * @return a square matrix
 */
vector<vector<int>> generateMatrix(int n) {
  if (n <= 0) return vector<vector<int>>();
  int row_begin = 0;
  int row_end = n - 1;
  int col_begin = 0;
  int col_end = n - 1;
  vector<vector<int>> result(n, vector<int>(n, 0));
  int k = 0;
  while (true) {
    for (int i = col_begin; i <= col_end; ++i)
      result[row_begin][i] = ++k;
    if (++row_begin > row_end) break;
    for (int i = row_begin; i <= row_end; ++i)
      result[i][col_end] = ++k;
    if (--col_end < col_begin) break;
    for (int i = col_end; i >= col_begin; --i)
      result[row_end][i] = ++k;
    if (--row_end < row_begin) break;
    for (int i = row_end; i >= row_begin; --i)
      result[i][col_begin] = ++k;
    if (++col_begin > col_end) break;
  }
  return result;
}
