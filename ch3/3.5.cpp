#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

/*
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  if (s1 > s2) {
    s1 += s2;
    cout << s1 << endl;
  } else {
    s2 += s1;
    cout << s2 << endl;
  }
  return 0;
}
*/

int main() {
  string concatStr, tempStr;
  while (cin >> tempStr) {
    concatStr += (concatStr.empty() ? "" : " ") + tempStr;
  }
  cout << concatStr << endl;
  return 0;
}