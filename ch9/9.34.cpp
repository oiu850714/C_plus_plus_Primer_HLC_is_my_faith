#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int main() {
  vector<int> vi{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto iter = vi.begin();
  while (iter != vi.end()) {
    if (*iter % 2)
      iter = vi.insert(iter, *iter);
    ++iter;
  }
  // I think Primer book forgot to print brackets for the while loop
  // if this true then code should like above

  // When *iter % 2 == 1, the iter will point to the same element after each
  // iteration, and iter will never == vi.end(). You can htop to see the program
  // eat memory dramatically
}