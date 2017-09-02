#include <string>
#include <iostream>

using namespace std;

static string leftPad(string& originalStr, int size, char padChar=' ') {
  if (size > originalStr.size()) {
    int left_size = size - originalStr.size();
    return string(left_size, padChar) + originalStr;
  } else {
    return originalStr;
  }
}
