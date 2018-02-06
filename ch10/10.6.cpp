#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::vector;
using std::fill_n;
using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;

int main() {
  vector<int> vec{9, 4, 8, 7, 9, 4, 5};
  fill_n(begin(vec), vec.size(), 0);
  for (auto i : vec)
    cout << i << " ";
  cout << endl;
}