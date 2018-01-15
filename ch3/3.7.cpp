#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main() {
  string input;
  cin >> input;
  for (char c : input)
    c = 'X';
  cout << input << endl; // input won't change
  return 0;
}