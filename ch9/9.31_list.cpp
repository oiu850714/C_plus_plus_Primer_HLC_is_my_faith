// list doesn't support operator+

#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::deque;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::forward_list;
int main() {
  list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto iter = lst.begin();
  while (iter != lst.end()) {
    if (*iter % 2) {
      iter = lst.insert(iter, *iter);
      ++iter;
      ++iter;
    } else
      iter = lst.erase(iter);
  }
}