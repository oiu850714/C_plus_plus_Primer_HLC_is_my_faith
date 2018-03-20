#include "18.9.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using Sales_data = Sales_item;

int main() {
  // use the hypothetical bookstore exceptions
  Sales_data item1, item2, sum;
  while (cin >> item1 >> item2) { // read two transactions
    try {
      sum = item1 + item2; // calculate their sum
      // use sum
      cout << sum << endl;
    } catch (const isbn_mismatch &e) {
      cerr << e.what() << ": left isbn(" << e.left << ") right isbn(" << e.right
           << ")" << endl;
    }
  }
}