#include <algorithm>
#include <iostream>
#include <list>

using std::list;
using std::cin;
using std::cout;
using std::endl;
using std::find;

using std::distance;
// using distance to find two iterators' distance
// seceond parameter must be reachable from first parameter
// by (possibly repeatedly) "incrementing" first.

int main() {
  list<int> li{9, 4, 8, 7, 0, 9, 4, 0, 5, 6, 6, 0, 6, 9, 8, 8};
  cout << "last 0's position(zero base): "
       << distance(find(li.rbegin(), li.rend(), 0), li.rend()) - 1 << endl;
}