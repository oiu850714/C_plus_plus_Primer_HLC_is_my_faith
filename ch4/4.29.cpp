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
  int x[10];
  int *p = x;
  cout << sizeof(x) / sizeof(*x) << endl; // 40 / 4 = 10
  cout << sizeof(p) / sizeof(*p) << endl; // 8 / 4 = 2
  // int* is 8 on x86-64
}