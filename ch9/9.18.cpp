#include <deque>
#include <iostream>
#include <string>

using std::deque;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
  deque<string> strings;
  string word;
  while (cin >> word) {
    strings.push_back(word);
  }
  for (auto it = strings.cbegin(); it != strings.cend(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}