#include "15.26.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::ostream;
using std::vector;

double print_total(ostream &os, const Quote &item, size_t n) {
  // depending on the type of the object bound to the item parameter
  // calls either Quote::net_price or Bulk_quote::net_price
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() // calls Quote::isbn
     << " # sold: " << n << " total due: " << ret << endl;
  return ret;
}

int main() {
  Quote q("book1", 50);
  Bulk_quote q2("book2", 50, 20, 0.25);
  vector<Quote> vec;
  vec.push_back(q);
  vec.push_back(q2); // only copy base-class part
  for (const auto &e : vec)
    print_total(cout, e, 30); // always use Quote::net_price
}