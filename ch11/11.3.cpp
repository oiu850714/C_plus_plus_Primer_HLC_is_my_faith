#include <iostream>
#include <map>
#include <string>

using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  string word;
  map<string, size_t> word_count;
  while (cin >> word) {
    ++word_count[word];
  }
  for (auto const &key_val_pair : word_count)
    cout << key_val_pair.first << " appear " << key_val_pair.second << " times"
         << endl;
}