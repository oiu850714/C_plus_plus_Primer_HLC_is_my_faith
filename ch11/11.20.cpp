#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::vector;

int main() {
  string word;
  map<string, size_t> word_count;
  while (cin >> word) {
    auto ret = word_count.insert({word, 1});
    // ex 11.20
    // subscripting version is more readable
    if (!ret.second) {
      //++word_count[word];
      ++ret.first->second;
    }
  }
  map<string, size_t>::iterator map_it = word_count.begin();
  while (map_it != word_count.end()) {
    cout << map_it->first << " occurs " << map_it->second << " times" << endl;
    ++map_it;
  }
}