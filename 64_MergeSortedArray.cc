#include <cstdio>

//由于A的后面的空的，所以逆序排是最好的
void mergeSortedArray(int A[], int m, int B[], int n) {
  int pos = m + n - 1;
  m--;
  n--;
  while(m >= 0 && n >= 0) {
    if (A[m] > B[n])
      A[pos--] = A[m--];
    else
      A[pos--] = B[n--];
  }
  while(m >= 0)
    A[pos--] = A[m--];
  while(n >= 0)
    A[pos--] = B[n--];
}

int main() {
  int A[] = { 1, 2, 4 };
  int B[] = { 3, 5 };
  mergeSortedArray(A, 3, B, 2);
  for (int i = 0; i < 5; ++i)
    printf("%d ", A[i]);
  return 0;
}
