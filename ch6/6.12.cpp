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

void swap(int &a, int &b) {
  int swap_temp = a;
  a = b;
  b = swap_temp;
}
int main() {
  int i_94 = 94, i_87 = 87;
  swap(i_94, i_87);
  cout << "i_94: " << i_94 << " i_87: " << i_87 << endl;
}

// more readable, and less code to type