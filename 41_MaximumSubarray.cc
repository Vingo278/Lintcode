#include <vector>
#include <cstdio>

using namespace std;

int maxSubArray(vector<int> nums) {
    int sum, max = nums[0];
    //sum不能为负数
    if (nums[0] < 0)
        sum =  0;
    else
        sum = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        sum += nums[i];
        if (sum > 0) {
            if (sum > max)
                max = sum;
        } else
            sum = 0;
    }
    return max;
}

int main() {
    vector<int> vec {-2, 2, -3, 4, -1, 2, 1, -5, 3};
    printf("%d\n", maxSubarray(vec));
    return 0;
}
