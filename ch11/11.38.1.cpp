#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::vector;
using std::unordered_map;

int main() {
  string word;
  unordered_map<string, size_t> word_count;
  while (cin >> word) {
    ++word_count[word];
  }
  for (const auto &w : word_count) {
    cout << w.first << " occurs " << w.second << " times" << endl;
  }
}