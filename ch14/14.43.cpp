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
using std::modulus;

using namespace std::placeholders;

int main() {
  vector<int> ivec{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  int number;
  std::cin >> number;
  auto f = bind(modulus<int>(), number, _1);
  for (auto e : ivec) {
    if (f(e) == 0) {
      std::cout << "divisible\n";
      return 0;
    }
  }
  std::cout << "not divisible\n";
  return 0;
}