// Binary Search Algorithm with duplications
// Same functions with std::lower_bound and std::upper_bound
// Useful when
//   - Binary search with custom containers
//   - Solving an optimization problem that can be converted to a "decision problem with binary search"

#include <algorithm>
#include <vector>

// Same with std::lower_bound
int BinsearchLowerBound(const std::vector<int>& vec, int val) {
  const int n = vec.size();
  int lo = 0, hi = n - 1;
  int ans = hi + 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (vec[mid] >= val) {
      hi = mid - 1;
      ans = mid;
    } else {
      lo = mid + 1;
    }
  }
  return ans;
}

// Same with std::upper_bound
int BinsearchUpperBound(const std::vector<int>& vec, int val) {
  const int n = vec.size();
  int lo = 0, hi = n - 1;
  int ans = hi + 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (vec[mid] > val) {
      hi = mid - 1;
      ans = mid;
    } else {
      lo = mid + 1;
    }
  }
  return ans;
}

// BinsearchLowerBoundLeft() == BinsearchLowerBound() - 1
int BinsearchLowerBoundLeft(const std::vector<int>& vec, int val) {
  const int n = vec.size();
  int lo = 0, hi = n - 1;
  int ans = lo - 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (vec[mid] >= val) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
      ans = mid;
    }
  }
  return ans;
}

// BinsearchUpperBoundLeft() == BinsearchUpperBound() - 1
int BinsearchUpperBoundLeft(const std::vector<int>& vec, int val) {
  const int n = vec.size();
  int lo = 0, hi = n - 1;
  int ans = lo - 1;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if (vec[mid] > val) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
      ans = mid;
    }
  }
  return ans;
}

int StdLowerBound(const std::vector<int>& vec, int val) {
  auto ans = std::lower_bound(vec.begin(), vec.end(), val);
  return std::distance(vec.begin(), ans);
}

int StdUpperBound(const std::vector<int>& vec, int val) {
  auto ans = std::upper_bound(vec.begin(), vec.end(), val);
  return std::distance(vec.begin(), ans);
}

#include <iostream>
#include <iomanip>

template <typename SearchFunc>
void SearchPrint(SearchFunc fn, const std::vector<int>& vec, int val) {
  int res = fn(vec, val);
  std::cout << "Find " << std::setw(2) << val << " : index " << std::setw(2) << res << std::endl;
}

int main() {
  // Array for test
  std::vector<int> v{10,10,10,10,20,20,20,30,30,30,30,40,50,50};

  std::cout << "idx ";
  for (int i = 0; i < v.size(); i++)
    std::cout << std::setw(2) << i << " ";
  std::cout << std::endl;

  std::cout << "val ";
  for (auto e : v) std::cout << e << " ";
  std::cout << std::endl;

  std::cout << std::endl;

  // Searches
  std::vector<int> vals_to_search{0, 10, 15, 20, 50, 60};

#define DO_SEARCH(fn) \
    std::cout << #fn << std::endl; \
    for (auto e : vals_to_search) \
      SearchPrint(fn, v, e); \
    std::cout << std::endl;

  DO_SEARCH(BinsearchLowerBound);
//  DO_SEARCH(StdLowerBound);
  DO_SEARCH(BinsearchUpperBound);
//  DO_SEARCH(StdUpperBound);
  DO_SEARCH(BinsearchLowerBoundLeft);
  DO_SEARCH(BinsearchUpperBoundLeft);

  return 0;
}
