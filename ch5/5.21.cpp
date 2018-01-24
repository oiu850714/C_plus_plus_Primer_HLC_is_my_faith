#include <cctype>
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
using std::isupper;

int main() {
  string prevStr, curStr;
  bool flag = false;
  while (cin >> curStr) {
    if (!isupper(curStr[0]))
      continue;

    if (prevStr == curStr) {
      flag = true;
      break;
    } else
      prevStr = curStr;
  }
  if (flag)
    cout << prevStr << " occurred twice" << endl;

  else
    cout << "no word was repeated" << endl;
}