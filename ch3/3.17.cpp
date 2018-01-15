#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

int main() {
  int counter = 0;
  string temp_str;
  while (cin >> temp_str) {
    counter++;
    for (auto &c : temp_str)
      c = toupper(c);
    cout << temp_str << (((counter % 8) != 0) ? " " : "\n");
  }
}