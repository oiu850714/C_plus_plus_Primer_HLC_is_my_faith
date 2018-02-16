// Assume file open success

#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::set;
using std::string;
using std::vector;
using std::getline;
using std::istringstream;

void parse_line(const std::string &line, const int line_num,
                map<string, set<int>> &word_map);
void runQueries(const vector<string> &line, map<string, set<int>> &word_map);

int main() {
  ifstream is("Story.txt");

  // ---------- construct query mqp ---------
  vector<string> lines;
  map<string, set<int>> word_map;

  string line;
  int line_num = 0;
  while (getline(is, line)) {
    lines.push_back(line);
    parse_line(line, line_num++, word_map);
  }
  // ----end of constructing query map-------

  runQueries(lines, word_map);
}

void parse_line(const std::string &line, const int line_num,
                map<string, set<int>> &word_map) {
  std::istringstream istrstm(line);
  std::string word;
  while (istrstm >> word) {
    word_map[word].insert(line_num);
  }
}

void runQueries(const vector<string> &lines, map<string, set<int>> &word_map) {
  while (true) {
    cout << "enter word to look for, or q to quit: ";
    string s;
    if (!(cin >> s) || s == "q")
      break;
    auto p = word_map.find(s);
    if (p != word_map.end()) {
      for (auto num : p->second) {
        cout << "(line " << num << ") ";
        cout << lines[num] << endl;
      }
    } else {
      cout << "word not found" << endl;
    }
  }
}