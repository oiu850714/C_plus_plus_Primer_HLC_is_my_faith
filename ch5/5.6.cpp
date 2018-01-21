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
  for (int grade = 0; cin >> grade && grade <= 100 && grade >= 0;) {
    cout << (grade < 60 ? scores[0] : scores[(grade - 50) / 10]);
    cout << ((grade == 100 || grade < 60)
                 ? ""
                 : (grade % 10 > 7 ? "+" : (grade % 10 < 3 ? "-" : "")));
    cout << endl;
  }
  return 0;
}