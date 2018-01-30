#include <array>
#include <iostream>
#include <string>
#include <vector>

using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  vector<int> c{0};
  // check that there are elements before dereferencing an iterator or calling
  // front or back
  if (!c.empty()) {
    // valand val2 are copies of the value of the first element in c
    auto val = *c.begin(), val2 = c.front();
    // val3 and val4 are copies of the of the last element in c
    auto last = c.end();
    auto val3 = *(--last); // can’t decrement forward_listiterators
    auto val4 = c.back();  // not supported by forward_list
  }
}

// val == val2 == val3 == val4 == c[0]