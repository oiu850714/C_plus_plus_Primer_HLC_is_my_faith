#include <deque>
#include <iostream>
#include <list>
#include <string>

using std::deque;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::list;

int main() {
  list<string> strings;
  string word;
  while (cin >> word) {
    strings.push_back(word); // 這個題目剛好只要把 deque 改成 list 就好了
  }
  for (auto it = strings.cbegin(); it != strings.cend(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}