#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using std::back_inserter;
using std::accumulate;
using std::begin;
using std::end;

int main() {
  std::vector<double> vec{1.1, 2.2, 3.3, 3.3,
                          2.4, 4.9}; // 1.1 + 2.2 + 3.3 + 3.3 + 2.4 + 4.9 = 17.2
  int i = accumulate(begin(vec), end(vec), 0); // i = 15
  // it looks like this:
  // int i = 0;
  // for(double e : vec)
  //    i = i + e;
  //    // every step converts i + e, which is double, to int and
  //    // assigns back to i
  std::cout << i << std::endl;
}
// SEE: https://github.com/Mooophy/Cpp-Primer/blob/master/ch10/ex10_03_04.cpp