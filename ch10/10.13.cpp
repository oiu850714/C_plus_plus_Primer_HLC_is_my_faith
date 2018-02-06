#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::partition;
using std::vector;
using std::string;
using std::begin;
using std::end;
using std::cin;
using std::cout;
using std::endl;
using std::istream_iterator;

bool length_less_5(const string &str) { return str.size() < 5; }

int main() {
  vector<string> vec_str(istream_iterator<string>(cin),
                         (istream_iterator<string>()));
  auto iter =
      partition(begin(vec_str), end(vec_str),
                length_less_5); // iter points first string that has size >= 5
  for (auto it = iter; it != cend(vec_str); ++it)
    cout << *it << " ";
  cout << endl;
}