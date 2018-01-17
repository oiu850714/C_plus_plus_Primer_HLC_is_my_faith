#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::getline;

int main() {
  vector<string> text;
  string text_line;
  while (getline(cin, text_line)) {
    text.push_back(text_line);
  }
  for (auto text_it = text.begin(); text_it != text.end() && !text_it->empty();
       text_it++) {
    for (auto line_it = text_it->begin(); line_it != text_it->end();
         line_it++) {
      *line_it = toupper(*line_it);
    }
    cout << *text_it << endl;
  }
}