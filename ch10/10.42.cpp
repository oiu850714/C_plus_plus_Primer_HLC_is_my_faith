#include <algorithm>
#include <iostream>
#include <list>
#include <string>

using std::cout;
using std::endl;
using std::list;
using std::string;

void elimDups(list<string> &words) {
  words.sort();
  words.unique();
}

int main() {
  list<string> words{"the",  "quick", "red",  "fox", "jumps",
                     "over", "the",   "slow", "red", "turtle"};
  elimDups(words);
  for (const auto &str : words)
    cout << str << " ";
  cout << endl;
}