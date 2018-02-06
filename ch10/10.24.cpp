#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::bind;
using std::string;
using std::vector;
using namespace std::placeholders;
using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::find_if;

bool func(int i, size_t sz) { return i > sz; }

int main() {
  vector<int> vec{1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                  11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

  string str;
  cin >> str;
  auto it = find_if(begin(vec), end(vec), bind(func, _1, str.size()));
  if (it != end(vec))
    cout << *it << endl;
  else
    cout << "not found" << endl;
}