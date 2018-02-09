#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>


using std::back_inserter;
using std::unique_copy;
using std::vector;
using std::list;
using std::sort;
using std::cin;
using std::cout;
using std::endl;
int main() {
  vector<int> vec_int{9, 4, 8, 7, 9, 4, 6, 6, 66, 88, 555, 444, 555};
  list<int> li;
  sort(begin(vec_int), end(vec_int));
  unique_copy(begin(vec_int), end(vec_int), back_inserter(li));
  for (auto i : li)
    cout << i << " ";
  cout << endl;
}