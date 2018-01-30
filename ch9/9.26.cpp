#include <deque>
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

int main() {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  vector<int> vec_int;
  list<int> lst_int;

  for (auto e : ia) { // copy
    vec_int.push_back(e);
    lst_int.push_back(e);
  }

  for (auto it = vec_int.begin(); it != vec_int.end();) {
    if (!(*it & 0x1))
      it = vec_int.erase(it);
    else
      it++;
  }

  for (auto it = lst_int.begin(); it != lst_int.end();) {
    if (*it & 0x1)
      it = lst_int.erase(it);
    else
      it++;
  }

  for (auto e : vec_int)
    cout << e << " ";
  cout << endl;

  for (auto e : lst_int)
    cout << e << " ";
  cout << endl;
}