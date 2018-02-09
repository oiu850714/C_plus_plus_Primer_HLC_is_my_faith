#include "../ch1/include/Sales_item.h"
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>

using Sales_data = Sales_item;

using std::map;
using std::list;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::multiset;

bool compareISBN(const Sales_data &lhs, const Sales_data &rhs) {
  return lhs.isbn() < rhs.isbn();
}

int main() {
  multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>
      bookstore(compareISBN);
  multiset<Sales_data,
           bool (*)(const Sales_data &, const Sales_data &)>::iterator set_it =
      bookstore.begin();
  // Ok Primer wants me to know how awesome C++11's auto is
}