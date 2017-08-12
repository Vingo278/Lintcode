#include <vector>
#include <cstdio>

using namespace std;

int binarySearch(vector<int> &array, int target) {
    int left = 0, right = array.size() - 1;
    while (right >= left) {
        int mid = left + (right - left) / 2;
        if (target <= array[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    if (array[left] == target) return left;
    return -1;
}

int main() {
    vector<int> vec {1, 2, 3, 3, 4, 5, 6};
    printf("%d\n", binarySearch(vec, 3));
    return 0;
}
