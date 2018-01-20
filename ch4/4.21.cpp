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

int main() {
  vector<int> vec{9, 4, 8, 7};
  for (auto it = vec.begin(); it != vec.end(); it++) {
    *it = (*it % 2 ? (2 * (*it)) : (*it));
  }
  for (auto e : vec)
    cout << e << " ";
  cout << endl;
  return 0;
}