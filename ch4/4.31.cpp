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
  vector<int> ivec(94, 87);
  vector<int>::size_type cnt = ivec.size();
  // assign values from size...1 to the elements in ivec
  for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
    ivec[ix] = cnt;
  // because we don't need the original value of ix and cnt, so in the third
  // part of loop header we use prefix increment and decrement operator

  for (vector<int>::size_type ix = 0; ix != ivec.size();)
    ivec[ix++] = cnt--;
  // can be change to this equivalent
}