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
using std::getline;

extern char next_text();
extern unsigned some_value();
extern int get_value();
extern int get_num();
extern unsigned get_bufCnt();

int main() {
  //(a)
  unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
  char ch = next_text();
  switch (ch) {
  case 'a':
    aCnt++;
    break; // need break statement
  case 'e':
    eCnt++;
    break; // need break statement
  default:
    iouCnt++;
    break; // better programming style with break
  }
  //(b)
  vector<int> ivec;
  unsigned index = some_value();
  int ix = get_value(); // this variable initialization should be placed outside
                        // the switch because it is used in two labels(case 1
                        // and default) of switch statement
  switch (index) {
  case 1:
    ivec[ix] = index;
    break;
  default:
    ix = ivec.size() - 1;
    ivec[ix] = index;
  }
  //(c)
  unsigned evenCnt = 0, oddCnt = 0;
  int digit = get_num() % 10;
  switch (digit) {
  case 1: // syntax error of switch label
  case 3:
  case 5:
  case 7:
  case 9:
    oddCnt++; // in Primer there is a type of "oddcnt"
    break;
  case 2: // syntax error for case label
  case 4:
  case 6:
  case 8:
  case 10:
    evenCnt++; // in Primer there is a type of "evencnt"
    break;
  }
  //(d)
  constexpr unsigned ival = 512, jval = 1024,
                     kval = 4096; // these should be const expression
  unsigned bufsize;
  unsigned swt = get_bufCnt();
  switch (swt) {
  case ival:
    bufsize = ival * sizeof(int);
    break;
  case jval:
    bufsize = jval * sizeof(int);
    break;
  case kval:
    bufsize = kval * sizeof(int);
    break;
  }
}