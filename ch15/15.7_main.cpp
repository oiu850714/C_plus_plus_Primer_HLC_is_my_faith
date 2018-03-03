#include "15.7.h"

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;
double print_total(ostream &os, const Quote &item, size_t n) {
  // depending on the type of the object bound to the item parameter
  // calls either Quote::net_price or Bulk_quote::net_price
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() // calls Quote::isbn
     << " # sold: " << n << " total due: " << ret << endl;
  return ret;
}

int main() {
  Bulk_limit bLimit("book_limit", 30, 50, 100, 0.1);

  print_total(cout, bLimit, 49);
  print_total(cout, bLimit, 50);
  print_total(cout, bLimit, 99);
  print_total(cout, bLimit, 100);
  print_total(cout, bLimit, 200);
}