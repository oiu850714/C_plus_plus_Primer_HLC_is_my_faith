#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::map;
using std::string;
using std::runtime_error;
using std::getline;

const string &transform(const string &s, const map<string, string> &m) {
  // the actual mapwork; this part is the heart of the program
  auto map_it = m.find(s);
  // if this word is in the transformation map
  if (map_it != m.cend())
    return map_it->second; // use the replacement word
  else
    return s; // otherwise return the original unchanged
}

map<string, string> buildMap(ifstream &map_file) {
  map<string, string> trans_map; // holds the transformations
  string key;                    // a word to transform
  string value;                  // phrase to use instead
  // read the first word into keyand the rest of the line into value
  while (map_file >> key && getline(map_file, value))
    if (value.size() > 1)               // check that there is a transformation
      trans_map[key] = value.substr(1); // skip leading space
    else
      throw runtime_error("no rule for " + key);
  return trans_map;
}

void word_transform(ifstream &map_file, ifstream &input) {
  auto trans_map = buildMap(map_file); // store the transformations
  for (auto e : trans_map) {
    cout << "word: " << e.first << ", phrase: " << e.second << endl;
  }
  string text;
  // hold each line from the input
  while (getline(input, text)) { // read a line of input
    istringstream stream(text);  // read each word
    string word;
    bool firstword = true; // controls whether a space is printed
    while (stream >> word) {
      if (firstword)
        firstword = false;
      else
        cout << " ";                      // print a space between words
      cout << transform(word, trans_map); // print the output
    }
    cout << endl; // done with this line of input
  }
}

int main(int argc, char **argv) {
  if (argc < 3) {
    cout << "Usage: " << argv[0] << " rule_file input_text.\n";
    return 1;
  }

  // assumue file open success
  ifstream map_file(argv[1]), input(argv[2]);
  word_transform(map_file, input);
}