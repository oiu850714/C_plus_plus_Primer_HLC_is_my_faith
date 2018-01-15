#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main() {
  string input1, input2, input3;
  cin >> input1;
  input2 = input3 = input1;

  for (auto &c : input1)
    c = 'X';
  cout << "range for: " << input1 << endl;

  decltype(input2.size()) i2 = 0;
  while (i2 < input2.size())
    input2[i2++] = 'X';
  cout << "while loop: " << input2 << endl;

  for (decltype(input3.size()) i3 = 0; i3 < input3.size(); i3++)
    input3[i3] = 'X';
  cout << "traditional for loop: " << input3 << endl;

  cout << "I prefer range for in this case" << endl;
  return 0;
}