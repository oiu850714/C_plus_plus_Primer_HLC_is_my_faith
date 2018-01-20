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
  vector<int> vec(10, 0);
  int ival = 0;
  int *ptr = &ival;

  //(a)
  ptr != 0 && *ptr++; // correct, not UB because logic AND evaluates ptr != 0
                      // first and then evaluates *ptr++;
  //(b)
  ival++ &&ival; // correct, not UB because logic evaluates ival++ first and
                 // evaluates ival(but, use new incremented value)
  //(c)
  vec[ival++] <= vec[ival];   // incorrect: UB
  vec[ival] <= vec[ival + 1]; // can be corrected like this
}