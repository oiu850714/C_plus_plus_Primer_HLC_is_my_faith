#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

#include <cctype>

int main() {
  for (string line; getline(cin, line); cout << endl) {
    for (auto c : line)
      if (!ispunct(c))
        cout << c;
  }
}