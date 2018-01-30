#include <vector>
using std::vector;

bool find_int(const vector<int>::const_iterator &cbegin,
              const vector<int>::const_iterator &cend, int i) {
  for (auto it = cbegin; it != cend; it++) {
    if (*it == i)
      return true;
  }
  return false;
}
