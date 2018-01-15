#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main() {
  string input;
  cin >> input;
  for (auto &c : input)
    c = 'X';
  cout << input << endl;
  return 0;
}