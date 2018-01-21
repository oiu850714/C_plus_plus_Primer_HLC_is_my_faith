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
  char c;
  int32_t aACnt = 0, eECnt = 0, iICnt = 0, oOCnt = 0, uUCnt = 0;
  while (cin >> c) {
    switch (c) {
    case 'a':
    case 'A':
      ++aACnt;
      break;
    case 'e':
    case 'E':
      ++eECnt;
      break;
    case 'i':
    case 'I':
      ++iICnt;
      break;
    case 'o':
    case 'O':
      ++oOCnt;
      break;
    case 'u':
    case 'U':
      ++uUCnt;
      break;
    default:
      break;
    }
  }
  cout << "#aA: " << aACnt << endl;
  cout << "#eE: " << eECnt << endl;
  cout << "#iI: " << iICnt << endl;
  cout << "#oO: " << oOCnt << endl;
  cout << "#uU: " << uUCnt << endl;
  return 0;
}
