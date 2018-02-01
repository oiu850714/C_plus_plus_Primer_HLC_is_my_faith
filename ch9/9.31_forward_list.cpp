// forward_list doesn't support operator+ and needs to use insert_after and
// erase_after

#include <deque>
#include <forward_list>
#include <iostream>
#include <iterator> // std::advance
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
using std::advance;

int main() {
  forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto curr = flst.begin(), prev = flst.before_begin();
  while (curr != flst.end()) {
    if (*curr % 2) {
      curr = flst.insert_after(prev, *curr);
      advance(curr, 2);
      advance(prev, 2);
      // example when *curr == 1
      //  p  c          // *curr % 2 == 1
      // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
      //  p  c          // curr = flst.insert_after(prev, *curr);
      // {0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
      //  p        c    // advance(curr, 2);
      // {0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
      //        p  c    // advance(prev, 2);
      // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    } else
      // example when *curr == 2
      //        p  c    // *curr % 2 == 0
      // {0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
      //        p  c    // curr = flst.erase_after(prev);
      // {0, 1, 1, 3, 4, 5, 6, 7, 8, 9};
      curr = flst.erase_after(prev);
  }

  for (auto i : flst)
    cout << i << " ";
  cout << endl;
}