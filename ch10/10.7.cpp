#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using std::vector;
using std::fill_n;
using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::list;

int main() {
  //(a)
  vector<int> vec1;
  list<int> lst;
  int i;
  while (cin >> i)
    lst.push_back(i);
  copy(lst.cbegin(), lst.cend(), vec1.begin()); // run-time error: vec1 is empty
  //(b)
  vector<int> vec2;
  vec2.reserve(10);            // reserve is covered in § 9.4 (p. 356)
  fill_n(vec2.begin(), 10, 0); // error: reserve change capacity, not size, and
                               // after fill_n, vec2's size is algo 0
  cout << vec2.size() << endl; // check vec2's size
  // And it's true that algorithm doesn't change the container's size LOL
}