#include <vector>
#include <cstdio>

using namespace std;

inline void swap(vector<int> &arr, size_t i, size_t j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

/**
 * 区间左闭右合，返回的是下标加1
 */
size_t partition(vector<int> &arr, size_t left, size_t right) {
    if (left == right) return left;
    size_t i = left;
    int key = arr[right - 1];
    for (size_t j = i; j < right; ++j) {
        if (arr[j] <= key) {
            swap(arr, i, j);
            ++i;
        }
    }
    return i;
}

int k_large(vector<int> &arr, size_t left, size_t right, size_t k) {
    if (k < left || k > right) return -1;
    size_t n = partition(arr, left, right);
    if (n == k)
        return arr[n - 1];
    else if (n > k)
        return k_large(arr, left, n - 1, k);
    else
        return k_large(arr, n, right, k);
}

int median(vector<int> &nums) {
    return k_large(nums, 0, nums.size(), (nums.size() + 1) / 2);
}

int main() {
    vector<int> vec {-1,-100,-3,-100,-2,-10000,500,0,0,0,-499,500,2000,0,0,0,3000,-100,-200,-10000,100000};
    printf("%d", median(vec));
    return 0;
}
