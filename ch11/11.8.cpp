#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
  vector<string> exclude_set;
  string word;
  while (cin >> word) {
    exclude_set.push_back(word);
  }
}
// if store input string like above, elements in exclude_set will be out of
// order and have duplicates but elements in set will be ordered and unique SEE:
// https://github.com/Mooophy/Cpp-Primer/tree/master/ch11#exercise-118