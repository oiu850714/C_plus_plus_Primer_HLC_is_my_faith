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
  int sz = 87;
  //(a)
  int ix = 0;
  for (ix = 0; ix != sz; ++ix) { /* .. . */
  }
  if (ix != sz) // ix was out of scope
    ;
  //(b)
  int ix2;
  for (; ix2 != sz; ++ix2) { // require initial statement
    /* ... */
  }
  //(c)
  for (int ix = 0; ix != sz; ++ix, ++sz) {
    // if ix != sz at first, it will be an infinite loop
    /* .. . */
  }
}