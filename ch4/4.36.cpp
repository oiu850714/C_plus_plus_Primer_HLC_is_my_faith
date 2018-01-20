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
  int i = 94;
  double d = .87;
  // i *= /*static_cast<int>*/ (d); result is 81
  i *= static_cast<int>(d); // result is 0
  cout << i << endl;
}