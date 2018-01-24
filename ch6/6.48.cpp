
#include <cassert>
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

int main() {
  string sought = "42";
  string s;
  while (cin >> s && s != sought) {
  }                    // empty body
  assert(s == sought); // use s == sought is better, that means when exiting the
                       // loop, it's impossible that s != sought unless there is
                       // a error e.g. EOF or invalid input
}