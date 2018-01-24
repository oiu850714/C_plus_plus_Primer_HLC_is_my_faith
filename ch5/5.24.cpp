#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <stdexcept>
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
using std::isupper;

int main() {
  int i = 0, j = 0;
  cin >> i >> j;
  if (j == 0)
    throw std::runtime_error("divisor is 0");
  cout << i / j << endl;
  return 0;
}