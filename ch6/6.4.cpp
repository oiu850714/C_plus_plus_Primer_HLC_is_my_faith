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

long long fact(long long i) {
  long long ret = 1;
  while (i) {
    ret *= i--;
  }
  return ret;
}

void interacting_with_user() {
  long long i;
  while (cin >> i) {
    if (i > 20)
      cout << "overflow" << endl;
    else if (i < 0)
      cout << "input cannot be negative" << endl;
    else
      cout << fact(i) << endl;
  }
}

int main() {
  interacting_with_user();
  return 0;
}