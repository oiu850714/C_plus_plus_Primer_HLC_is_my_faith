#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main() {
  string word;
  string line;
  while (cin >> word)
  // while(getline(cin, line))
  {
    cout << word << endl;
    // cout << line << endl;
  }
  return 0;
}