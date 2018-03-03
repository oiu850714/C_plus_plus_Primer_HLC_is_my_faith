#include "15.5.h"
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;
// calculate and print the price for the given number of copies, applying any
// discounts
double print_total(ostream &os, const Quote &item, size_t n) {
  // depending on the type of the object bound to the item parameter
  // calls either Quote::net_price or Bulk_quote::net_price
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() // calls Quote::isbn
     << " # sold: " << n << " total due: " << ret << endl;
  return ret;
}

int main() {
  Quote quote("book1", 50);
  Bulk_quote bquote("book2", 60, 50, 0.1);
  print_total(cout, quote, 100);

  print_total(cout, bquote, 49);
  print_total(cout, bquote, 50);
}