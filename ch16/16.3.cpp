template <typename T> int compare(const T &t1, const T &t2) {
  if (t1 < t2)
    return -1;
  if (t2 < t1)
    return 1;
  return 0;
}

#include "../ch1/include/Sales_item.h"
#include <iostream>

using Sales_data = Sales_item;

int main() { std::cout << compare(Sales_data("book1"), Sales_data("book2")); }
// link error: undefined reference to `operator<(Sales_item const&, Sales_item
// const&)'