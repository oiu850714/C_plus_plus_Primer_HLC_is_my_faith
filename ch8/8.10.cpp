#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using std::cin;
using std::getline;
using std::cout;
using std::endl;
using std::istringstream;
using std::vector;
using std::string;
using std::ifstream;

int main() {
  vector<string> file_content;
  string file_name;
  cin >> file_name;
  ifstream in(file_name);
  if (!in) {
    cout << "file open failed\n";
    return 1;
  }
  string line;
  while (getline(in, line)) {
    file_content.push_back(line);
  }
  for (const auto &e : file_content) {
    istringstream is(e);
    string word;
    while (is >> word) {
      cout << word << " ";
    }
  }
  cout << endl;
}