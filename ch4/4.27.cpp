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
  unsigned long ul1 = 3, ul2 = 7;
  //(a)
  ul1 &ul2;
  //  0...011
  //& 0..0111
  //= 0..0011 = 3
  //(b)
  ul1 | ul2;
  //  0...011
  //| 0..0111
  //= 0..0111 = 7
  //(c)
  ul1 &&ul2;
  // nonzero(true) && nonzero(true) == true
  //(d)
  ul1 || ul2;
  // nonzero(true) || nonzero(true) == true
}