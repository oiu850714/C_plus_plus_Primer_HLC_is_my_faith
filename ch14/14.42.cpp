#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>

#include <iostream>

using std::find_if;
using std::count_if;
using std::transform;
using std::bind;
using std::string;
using std::vector;

using std::greater;
using std::not_equal_to;
using std::multiplies;

using namespace std::placeholders;

int main() {
  vector<int> ivec{1, 111, 1111, 11111};
  vector<string> svec{"pooh", "pooh", "poo", "pooh", "poooh"};

  // (a) Count the number of values that are greater than 1024
  std::cout << count_if(ivec.begin(), ivec.end(),
                        bind(greater<int>(), _1, 1024))
            << std::endl;
  // (b) Find the first string that is not equal to pooh
  std::cout << *find_if(svec.begin(), svec.end(),
                        bind(not_equal_to<string>(), _1, "pooh"))
            << std::endl;
  // (c) Multiply all values by 2
  transform(ivec.begin(), ivec.end(), ivec.begin(),
            bind(multiplies<int>(), _1, 2));
  for (auto e : ivec)
    std::cout << e << " ";
  std::cout << std::endl;
}
