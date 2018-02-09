#include <algorithm>
#include <iterator>
#include <set>
#include <string>
#include <vector>

using std::multiset;
using std::vector;
using std::string;
using std::copy;
using std::inserter;
using std::back_inserter;

int main() {
  multiset<string> c{"hsilu", "so", "cute"};
  vector<string> v{"hsilu", "so", "cute"};
  copy(v.begin(), v.end(), inserter(c, c.end()));
  // add all elements in v to c
  copy(v.begin(), v.end(), back_inserter(c));
  // illegal: back_inserter uses container's push_back, but multiset doesn't
  // have push_back
  copy(c.begin(), c.end(), inserter(v, v.end()));
  // add all elements in c to v, new elements' order are sorted in v
  copy(c.begin(), c.end(), back_inserter(v));
  // add all elements in c to v, new elements' order are sorted in v
}