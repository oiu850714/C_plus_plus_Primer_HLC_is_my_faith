#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::scanf;
using std::strcmp;

int main() {
  char s1[4096], s2[4096];
  scanf("%s%s", s1, s2);
  int result = strcmp(s1, s2);
  if (result == 0) {
    cout << "s1 == s2" << endl;
  } else if (result > 0) {
    cout << "s1 > s2" << endl;
  } else {
    cout << "s1 < s2" << endl;
  }

  string cppstr1(s1), cppstr2(s2);
  if (cppstr1 == cppstr2) {
    cout << "cppstr1 == cppstr2" << endl;
  } else if (cppstr1 > cppstr2) {
    cout << "cppstr1 > cppstr2" << endl;
  } else {
    cout << "cppstr1 < cppstr2" << endl;
  }
  return 0;
}