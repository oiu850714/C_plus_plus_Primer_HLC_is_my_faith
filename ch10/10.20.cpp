#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::begin;
using std::end;
using std::cin;
using std::cout;
using std::endl;

int main() {
  vector<string> vec_str{"greater6", "equal6",   "less6",    "equal6", "equal6",
                         "equal6",   "greater6", "greater6", "less6",  "less6"};
  cout << count_if(begin(vec_str), end(vec_str), [](const string &s) {
    return s.size() > 6;
  }) << endl;
}