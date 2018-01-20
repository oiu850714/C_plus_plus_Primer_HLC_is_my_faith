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
  //(a)
  cout << -30 * 3 + 21 / 5 << endl;
  // -86
  //(b)
  cout << -30 + 3 * 21 / 5 << endl;
  // -18
  //(c)
  cout << 30 / 3 * 21 % 5 << endl;
  // 0
  //(d)
  cout << -30 / 3 * 21 % 4 << endl;
  // -2
}