// SEE: https://github.com/Mooophy/Cpp-Primer/tree/master/ch05#exercise-516

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
  // while idiomatic
  int i;
  while (cin >> i)
    ;
  // ...

  // same as for
  for (int i = 0; cin >> i;)
    ;
  // ...

  // for idiomatic
  for (int i = 0; i != size; ++i)
    ;
  // ...

  // same as while
  int i = 0;
  while (i != size) {
    // ...
    ++i;
  }
}