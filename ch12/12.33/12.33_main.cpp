#include "12.33.h"
#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;

void runQueries(ifstream &is) {
  TextQuery tq(is);

  do {
    cout << "enter word to look for, or q to quit: ";
    string s;
    if (!(cin >> s) || s == "q")
      break;
    print(cout, tq.query(s));
  } while (true);
  // Both are acceptable in this case I think...
}

int main() {
  cout << "input file name: ";
  string file_name;
  cin >> file_name;
  ifstream is(file_name);
  if (!is) {
    cout << "open file failed." << endl;
    return 1;
  }

  // tq.print_line_and_map();
  runQueries(is);
}