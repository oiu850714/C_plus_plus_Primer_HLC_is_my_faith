#include <deque>
#include <iostream>
#include <list>
#include <string>

using std::deque;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::list;

int main() {
  list<int> list_int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  deque<int> odd, even;
  for (auto i : list_int) {
    i & 0x1 ? odd.push_back(i) : even.push_back(i);
  }

  cout << "odd: ";
  for (auto i : odd)
    cout << i << " ";
  cout << endl;

  cout << "even: ";
  for (auto i : even)
    cout << i << " ";
  cout << endl;
}