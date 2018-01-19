#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

int main() {
  const char ca[] = {'h', 'e', 'l', 'l', 'o'}; // not null-terminated
  const char *cp = ca;
  while (*cp) { // becase the array cp points to is not null terminated, the
                // result is UB
    cout << *cp << endl;
    ++cp;
  }
}