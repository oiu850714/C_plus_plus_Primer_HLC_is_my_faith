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
using std::isupper;
using std::scanf;
using std::strcmp;
using std::string;
using std::strncat;
using std::strncpy;
using std::vector;
using std::tolower;

int compare_int(const int *ptr, const int i) { return (*ptr > i ? *ptr : i); }

int main() {
  int i = 94, j = 87;
  cout << compare_int(&i, j) << endl;
}