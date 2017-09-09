#include <vector>

using namespace std;

/*
 * @param matrix: a matrix of m x n elements
 * @return: an integer list
 */
vector<int> spiralOrder(vector<vector<int>> &matrix) {
  if (matrix.empty()) return vector<int>();
  int row_begin = 0;
  int row_end = matrix.size() - 1;
  int col_begin = 0;
  int col_end = matrix[0].size() - 1;
  vector<int> result;
  while (true) {
    for (int i = col_begin; i <= col_end; ++i)
      result.push_back(matrix[row_begin][i]);
    if (++row_begin > row_end) break;
    for (int i = row_begin; i <= row_end; ++i)
      result.push_back(matrix[i][col_end]);
    if (--col_end < col_begin) break;
    for (int i = col_end; i >= col_begin; --i)
      result.push_back(matrix[row_end][i]);
    if (--row_end < row_begin) break;
    for (int i = row_end; i >= row_begin; --i)
      result.push_back(matrix[i][col_begin]);
    if (++col_begin > col_end) break;
  }
  return result;
}
