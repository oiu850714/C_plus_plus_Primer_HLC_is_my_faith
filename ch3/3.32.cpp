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
  int ia1[array_size];

  for (size_t ix = 0; ix < array_size /*out of range when ix == 10*/; ++ix)
    ia1[ix] = ix;
  int ia2[array_size];
  for (size_t i = 0; i < array_size; ++i)
    ia2[i] = ia1[i];

  cout << "ia1: ";
  for (auto e : ia1)
    cout << e << " ";
  cout << endl;
  cout << "ia2: ";
  for (auto e : ia2)
    cout << e << " ";
  cout << endl;

  vector<int> v1;
  for (auto e : ia2)
    v1.push_back(e);
  auto v2 = v1;

  cout << "v1: ";
  for (auto e : v1)
    cout << e << " ";
  cout << endl;
  cout << "v2: ";
  for (auto e : v2)
    cout << e << " ";
  cout << endl;
  return 0;
}