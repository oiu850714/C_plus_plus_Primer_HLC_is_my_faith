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
  const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
  for (int grade = 0; cin >> grade && grade <= 100;) {
    if (grade < 60) {
      cout << scores[0] << endl;
    } else {
      cout << scores[(grade - 50) / 10];
      if (grade != 100) {
        if (grade % 10 > 7) {
          cout << "+";
        } else if (grade % 10 < 3) {
          cout << "-";
        }
      }
      cout << endl;
    }
  }
  return 0;
}