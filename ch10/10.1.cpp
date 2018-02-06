#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::cin;
using std::count;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::vector;

int main() {
  vector<int> v(istream_iterator<int>(cin), (istream_iterator<int>()));
  // notice the brackets and parenthesis used for second parameter, the
  // parentheses around second parameter is mandatory, otherwise v will be
  // treated as function declaration
  // SEE: https://www.wikiwand.com/en/Most_vexing_parse#/Example_with_classes

  // equivalent 1:
  /*
    istream_iterator<int> is(cin), eof;
    vector<int> v(is, eof);
  */

  // equivalent 2:
  /*
    vector<int> v{istream_iterator<int>(cin), istream_iterator<int>()};
    // universal initialisation syntax
  */

  cout << count(v.begin(), v.end(), 87) << endl;
}