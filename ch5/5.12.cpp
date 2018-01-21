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
  char c1, c2;
  int32_t ffCnt = 0, flCnt = 0, fiCnt = 0;
  while (cin >> c1 >> c2) {
    if (c1 == 'f' && c2 == 'f') {
      ++ffCnt;
    } else if (c1 == 'f' && c2 == 'l') {
      ++flCnt;
    } else if (c1 == 'f' && c2 == 'i') {
      ++fiCnt;
    }
  }
  cout << "#ff: " << ffCnt << endl;
  cout << "#fl: " << flCnt << endl;
  cout << "#fi: " << fiCnt << endl;
  return 0;
}
