#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using std::cin;
using std::count;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::vector;
using std::accumulate;

int main() {
  vector<int> v(istream_iterator<int>(cin), (istream_iterator<int>()));
  cout << accumulate(v.cbegin(), v.cend(), 0) << endl;
}
