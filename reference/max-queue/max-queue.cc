// A special queue with two stacks that can do
//   - Push element to rear
//   - Pop element from front
//   - Keep max value(Getting max value is O(1))
// Note that some corner cases are unhandled
// (e.g. Get max value when the queue is empty)
// Reference : https://codeforces.com/blog/entry/63274 (Problem F2)

#include <algorithm>
#include <stack>
#include <utility>

template <typename T>
struct MaxQueue {
  std::stack<std::pair<T, T>> s1, s2;

  int size() { return s1.size() + s2.size(); }

  void push(T val) {
    T mx = s2.empty() ? val : s2.top().second;
    s2.push({val, std::max(val, mx)});
  }

  void pop() {
    if (s1.empty()) {
      while (!s2.empty()) {
        auto v = s2.top().first;
        T mx = s1.empty() ? v : std::max(v, s1.top().second);
        s1.push({v, mx});
        s2.pop();
      }
    }
    s1.pop();
  }

  T maxval() {
    if (!s2.empty() && !s1.empty()) return std::max(s1.top().second, s2.top().second);
    if (!s1.empty()) return s1.top().second;
    return s2.top().second;
  }
};


#include <iostream>

int main() {
  MaxQueue<int> maxq;

  maxq.push(4);
  maxq.push(2);
  maxq.push(1);
  maxq.push(3);
  // Queue : 4 2 1 3
  std::cout << maxq.size() << " " << maxq.maxval() << std::endl; // 4

  maxq.pop();
  maxq.pop();
  // Queue : 1 3
  std::cout << maxq.size() << " " << maxq.maxval() << std::endl; // 3

  return 0;
}
