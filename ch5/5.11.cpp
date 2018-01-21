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

int main() {
  // note: cin >> char will omit whitespace character by default
  // or use this: cin >> std::noskipws;
  int32_t aACnt = 0, eECnt = 0, iICnt = 0, oOCnt = 0, uUCnt = 0, spaceCnt = 0,
          tabCnt = 0, newlineCnt = 0;
  string line;
  while (getline(cin, line)) {
    ++newlineCnt; // geline will discard newline
    for (decltype(line.size()) i = 0; i < line.size(); i++) {
      switch (line[i]) {
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
      case ' ':
        ++spaceCnt;
        break;
      case '\t':
        ++tabCnt;
        break;
      default:
        break;
      }
    }
  }
  cout << "#aA: " << aACnt << endl;
  cout << "#eE: " << eECnt << endl;
  cout << "#iI: " << iICnt << endl;
  cout << "#oO: " << oOCnt << endl;
  cout << "#uU: " << uUCnt << endl;
  cout << "#space: " << spaceCnt << endl;
  cout << "#tab: " << tabCnt << endl;
  cout << "newline: " << newlineCnt << endl;
  return 0;
}
