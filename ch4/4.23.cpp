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
  string s = "word";
  string pl = s + s[s.size() - 1] == 's' ? "" : "s";
  // actual meaning: ((s + s[s.size() - 1]) == 's') ? "" : "s";
  // cannot compare string with character literal
  string p2 = s + (s[s.size() - 1] == 's' ? "" : "s");
  // correct version
}