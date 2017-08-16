#include <vector>
#include <cstdio>
#include <algorithm>
#include <iterator>

using namespace std;

class Interval {
 public:
  int start, end;
  Interval(int start, int end) {
    this->start = start;
      this->end = end;
  }
};

vector<Interval> merge(vector<Interval> &intervals) {
  if (intervals.size() <= 1) return intervals;
  //快排
  sort(intervals.begin(), intervals.end(), 
      [](const Interval &val1, const Interval &val2)
      { return val1.start < val2.start ? true : false; }
      );
  vector<Interval>::iterator end_node = intervals.begin();
  for (auto iter = intervals.begin() + 1; iter != intervals.end(); ++iter) {
    //区间比当前大，插入
    if (iter->start > end_node->end) {
      end_node++;
      *end_node = *iter;
    //区间有合集，包括相邻
    } else if (iter->end > end_node->end) {
      end_node->end = iter->end;
    }
  }
    intervals.erase(end_node + 1, intervals.end());
    return intervals;
}

int main() {
  vector<Interval> vals { Interval(1,3), Interval(2, 6), Interval(8, 10), Interval(15, 18) };
  vals = merge(vals);
  for (Interval &val : vals) 
    printf("%d %d\n", val.start, val.end);
  return 0;
}
