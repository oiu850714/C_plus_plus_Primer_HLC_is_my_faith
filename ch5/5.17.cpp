#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::scanf;
using std::strcmp;
using std::string;
using std::strncat;
using std::strncpy;
using std::vector;

bool is_prefix(vector<int> &small_vec, vector<int> &big_vec) {
  if (small_vec.size() > big_vec.size())
    return is_prefix(big_vec, small_vec);
  for (decltype(small_vec.size()) i = 0; i < small_vec.size(); i++) {
    if (small_vec[i] != big_vec[i])
      return false;
  }
  return true;
}

int main() {
  vector<int> v1, v2;
  /* fill ints to v1 and v2 */
  cout << (is_prefix(v1, v2) ? "true" : "false") << endl;
}