#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using std::back_inserter;
using std::cin;
using std::copy;
using std::cout;
using std::endl;
using std::find;
using std::list;
using std::vector;

int main() {
  vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  list<int> li;
  copy(vec.crbegin() + 3, vec.crbegin() + 8, back_inserter(li));
  copy(li.cbegin(), li.cend(), std::ostream_iterator<int>(cout, " "));
  cout << endl;
}