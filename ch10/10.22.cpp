#include <algorithm>
#include <functional>
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
using std::bind;
using namespace std::placeholders;

bool len_less_or_equal_to_sz(const string &str, size_t sz) {
  return str.size() <= sz;
}

int main() {
  vector<string> vec_str{"greater6", "equal6",   "less6",    "equal6", "equal6",
                         "equal6",   "greater6", "greater6", "less6",  "less6"};
  cout << count_if(begin(vec_str), end(vec_str),
                   bind(len_less_or_equal_to_sz, _1, 6))
       << endl;
}