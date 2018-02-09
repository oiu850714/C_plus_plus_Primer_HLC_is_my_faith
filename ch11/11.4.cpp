#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using std::map;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::transform;
using std::remove_if;

string &ignore_punc_case(string &word) {
  transform(word.begin(), word.end(), word.begin(), ::tolower);
  word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
  return word;
}

int main() {
  string word;
  map<string, size_t> word_count;
  while (cin >> word) {
    ignore_punc_case(word);
    ++word_count[word];
  }
  for (auto const &key_val_pair : word_count)
    cout << key_val_pair.first << " appear " << key_val_pair.second << " times"
         << endl;
}