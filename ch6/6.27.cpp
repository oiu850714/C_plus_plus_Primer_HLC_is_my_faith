#include <cctype>
#include <cstdio>
#include <cstring>
#include <initializer_list>
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
using std::isupper;
using std::scanf;
using std::strcmp;
using std::string;
using std::strncat;
using std::strncpy;
using std::vector;
using std::initializer_list;

int sum(initializer_list<int> il) {
  int result = 0;
  for (auto &e : il) {
    result += e;
  }
  return result;
}

int main() {
  int i_94 = 94, i_87 = 87, i_666 = 666, i_8888 = 8888, i_love_hsilu = 76;
  cout << sum({i_94, i_87, i_666, i_8888, i_love_hsilu}) << endl;
}