#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

int main() {
  constexpr size_t array_size = 10;
  int ia[array_size];
  for (size_t ix = 1 /*didn't access element at index 0 */;
       ix < array_size /*out of range when ix == 10*/; ++ix)
    ia[ix] = ix;
  for (auto e : ia)
    cout << e << " ";
  cout << endl;
  return 0;
}