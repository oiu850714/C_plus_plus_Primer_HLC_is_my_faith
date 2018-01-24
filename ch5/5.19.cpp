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
  string s1, s2;
  cin >> s1 >> s2;
  do {
    cout << (s1 > s2 ? "s1 > s2" : "s1 < s2") << endl;
  } while (cin >> s1 >> s2);
}