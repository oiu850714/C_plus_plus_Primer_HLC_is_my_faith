#include <vector>
using std::vector;

auto find_int(const vector<int>::const_iterator &cbegin,
              const vector<int>::const_iterator &cend, int i)
    -> vector<int>::const_iterator {
  for (auto it = cbegin; it != cend; it++) {
    if (*it == i)
      return it;
  }
  return cend;
}
