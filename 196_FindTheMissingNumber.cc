#include <vector>

using namespace std;

/**    
 * 简单：a ^ a = 0，同时异或是可交换的，所以把所以已知的数和所有可能的数做异或后
 * 就会剩下最后缺少的数。
 * 其实还可以求和，然后减去（实际上是边加边减，保证不溢出）。
 * @param nums: a vector of integers
 * @return: an integer
 */
int findMissing(vector<int> &nums) {
  int result = nums.size();
  for (int i = 0; i < nums.size(); ++i) {
    result = result ^ nums[i] ^ i;
  }
  return result;
}
