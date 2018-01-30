#include <vector>

using std::vector;

int main() {
  vector<int> v1;
  const vector<int> v2;
  // auto it1 = v1.begin(), it2 = v2.begin();
  // original code is error, auto
  // declaration's initializers have
  // different type
  auto it1 = v1.begin();                     // vector<int>::iterator
  auto it2 = v2.begin();                     // vector<int>::const_iterator
  auto it3 = v1.cbegin(), it4 = v2.cbegin(); // vector<int>::const_iterator
}