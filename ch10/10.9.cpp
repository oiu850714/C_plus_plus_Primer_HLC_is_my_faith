#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::cbegin;
using std::cend;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::istream_iterator;
using std::sort;
using std::unique;
using std::string;

void printVec(const vector<string> &vec_str) {
  for (const auto &str : vec_str)
    cout << str << " ";
  cout << endl;
}

void elimDups(vector<string> &vec_str) {
  cout << "original: ";
  printVec(vec_str);

  cout << "sort: ";
  sort(begin(vec_str), end(vec_str));
  printVec(vec_str);

  cout << "eliminate duplicates: ";
  vec_str.erase(unique(begin(vec_str), end(vec_str)), vec_str.end());
  printVec(vec_str);
}

int main() {
  vector<string> vec_str(istream_iterator<string>(cin),
                         (istream_iterator<string>()));
  elimDups(vec_str);
}