#include "10.12.h"

#include <algorithm>
#include <iostream>
#include <vector>

using std::sort;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

bool compareIsbn(const Sales_data &data1, const Sales_data &data2) {
  return data1.isbn() < data2.isbn();
}

int main() {
  vector<Sales_data> items;
  Sales_data item;
  while (read(cin, item)) {
    items.push_back(item);
  }
  sort(items.begin(), items.end(), compareIsbn);
  for (const auto &e : items)
    print(cout, e) << endl;
}
