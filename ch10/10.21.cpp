#include <iostream>
using std::cout;
using std::endl;

int main() {
  int i = 87;
  auto f = [&i]() -> bool {
    if (i) {
      --i;
      return false;
    } else
      return true;
  };

  while (!f()) {
    cout << i << endl;
  }
}