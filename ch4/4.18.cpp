#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::begin;
using std::end;
using std::scanf;
using std::strcmp;
using std::strncpy;
using std::strncat;

int main() {
  vector<int> v;
  for (decltype(v.size()) i = 0; i < 87; i++)
    v.push_back(i);
  auto pbeg = v.begin();
  while (pbeg != v.end() && *pbeg >= 0)
    cout << *++pbeg << endl;
  // it will print from v[i] to v[v.size()]
  // 1. skip v[0]
  // 2. print element is v.end(), which is UB, if all element >= 0
}