#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

using std::cin;
using std::count;
using std::cout;
using std::endl;
using std::istream_iterator;
using std::list;
using std::string;

int main() {
  list<string> v(istream_iterator<string>(cin), (istream_iterator<string>()));
  cout << count(v.begin(), v.end(), "hsilu") << endl;
}