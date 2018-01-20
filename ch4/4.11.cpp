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
  int a = 0, b = 0, c = 0, d = 0;
  if (cin >> a >> b >> c >> d) {
    if (a < b && b << c && c << d)
      cout << "true" << endl;
    else
      cout << "false" << endl;
  } else {
    cout << "please input four number" << endl;
  }
  return 0;
}