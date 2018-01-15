#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main() {
  string s;
  cout << s[0] << endl;
  return 0;
  // invalid program, indexing empty string is undefined behavior
}