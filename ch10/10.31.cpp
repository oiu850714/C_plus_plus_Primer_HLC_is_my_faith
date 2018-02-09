#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::sort;
using std::unique_copy;
using std::copy;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
using std::cin;
using std::cout;
using std::endl;

int main() {
  vector<int> vec((istream_iterator<int>(cin)), (istream_iterator<int>()));
  sort(vec.begin(), vec.end());
  unique_copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}