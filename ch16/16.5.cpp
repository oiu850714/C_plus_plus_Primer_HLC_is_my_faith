#include <iostream>

using std::cout;
using std::endl;

/* §6.2.4
void print(int (&arr)[10]) {
  for (auto elem : arr)
    cout << elem << endl;
}
*/

template <typename T, size_t N> void print(const T (&arr)[N]) {
  for (const auto &elem : arr)
    cout << elem << " ";
  cout << endl;
}

#include <string>

int main() {
  int arr1[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::string arr2[8]{"oiu",  "like", "hsilu", "yoyo",
                      "niku", "oiu",  "sucks", "!\n"};
  print(arr1);
  print(arr2);
}