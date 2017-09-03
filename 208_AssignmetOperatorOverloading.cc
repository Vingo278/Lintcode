#include <cstring>
#include <iostream>

using namespace std;

class Solution {
 public:
  char *m_pData;
  Solution() {
    this->m_pData = NULL;
  }
  Solution(char *pData) {
    int size = strlen(pData) + 1;
    m_pData = new char[size];
    strncpy(m_pData, pData, size);
  }

  // 1. 自赋值
  // 2. 参数的m_pData是否NULL
  Solution &operator=(const Solution &object) {
    // write your code here
    if (this == &object) return *this;
    if (m_pData)
      delete m_pData;
    if (object.m_pData) {
      int size = strlen(object.m_pData) + 1;
      m_pData = new char[size];
      strncpy(m_pData, object.m_pData, size);
    } else {
      m_pData = NULL;
    }
    return *this;
  }

  ~Solution() {
    if (m_pData)
      delete m_pData;
  }
};

int main() {
  Solution A("abcd");
  Solution B("abc");
  cout << A.m_pData << ';' << B.m_pData << endl;
  A = B;
  cout << A.m_pData << ';' << B.m_pData << endl;
  return 0;
}
