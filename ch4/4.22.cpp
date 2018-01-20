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
  int grade;
  if (cin >> grade) {
    string finalgrade =
        (grade >= 90)
            ? "high pass"
            : (grade >= 75) ? "pass" : (grade >= 60) ? "low pass" : "fail";
    cout << finalgrade << endl;
    string if_finalgrade;
    if (grade >= 90) {
      if_finalgrade = "high pass";
    } else if (grade >= 75) {
      if_finalgrade = "pass";
    } else if (grade >= 60) {
      if_finalgrade = "low pass";
    } else {
      if_finalgrade = "fail";
    }
    cout << "if version: " << if_finalgrade << endl;
  } else {
    cout << "please input grade" << endl;
  }
  // of course if version is more readable
  return 0;
}