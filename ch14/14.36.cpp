#include "14.35.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main() {
  vector<string> svec;
  while (cin) {
    svec.push_back(PrintString()(cin));
  }

  for (const auto &s : svec)
    cout << s << endl;
}