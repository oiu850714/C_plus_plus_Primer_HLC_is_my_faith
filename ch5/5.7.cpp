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

extern int get_value();

int main() {
  int ival = 0, ival1 = 0, ival2 = 0, minval = 0, occurs = 0;
  //(a)
  if (ival1 != ival2)
    ival1 = ival2 /* correct: need a semicolon */;
  else
    ival1 = ival2 = 0;
  //(b)
  if (ival < minval) {
    minval = ival;
    occurs = 1; // cannot know what occurs do, but if it relates to the
                // condition's logic, braces should be added to include above
                // two lines in if's scope
  }
  //(c)
  if (int ival = get_value())
    cout << "ival = " << ival << endl;
  else // should use else if when ival == 0 it should print "ival = 0\n"
    cout << "ival = 0\n";
  //(d)
  if (ival = 0) // programmer's intention may be ival == 0
    ival = get_value();
}