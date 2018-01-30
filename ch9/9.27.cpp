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
  forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto prev = flst.before_begin(); // denotes element "off=the start" offlst
  auto curr = flst.begin();        // denotes the first element in flst
  while (curr != flst.end()) {     // while there are still elements to process
    if (*curr % 2) {               // if the element is odd
      curr = flst.erase_after(prev); // erase it and move curr
    } else {
      ++prev; // move the iterators to denote the next
      ++curr; // element and one before the next element
    }
  }

  for (auto e : flst)
    cout << e << " ";
  cout << endl;
}