#include <cmath>
#include <cstdio>

// 扔楼层数（在上一次的基础上的）：
// x, x-1, x-2, x-3...
// 假设第一次碎了，那么总共次数1 + (x - 1) = x
// 2: 2 + (x - 2) = x
// 3: 3 + (x - 3) = x
// ...
// 所以用求和公式求出x即可。n = (1 + x) * x / 2
int dropEggs(int n) {
  double result = sqrt(2.0 * n + 0.25) - 0.5;
  int result_int = static_cast<int>(result);
  if (fabs(result - result_int) < 0.0000000001)
    return result;
  else
    return result + 1;
}

int main() {
  printf("%d\n", dropEggs(10));
  printf("%d\n", dropEggs(100));
  return 0;
}

