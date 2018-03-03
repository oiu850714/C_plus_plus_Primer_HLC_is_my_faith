#include "15.26.h"
#include <iostream>
#include <memory>
#include <vector>

using std::cout;
using std::endl;
using std::ostream;
using std::vector;
using std::shared_ptr;
using std::make_shared;

double print_total(ostream &os, const Quote &item, size_t n) {
  // depending on the type of the object bound to the item parameter
  // calls either Quote::net_price or Bulk_quote::net_price
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() // calls Quote::isbn
     << " # sold: " << n << " total due: " << ret << endl;
  return ret;
}

int main() {
  vector<shared_ptr<Quote>> vec;
  vec.push_back(make_shared<Quote>("book1", 50));
  vec.push_back(make_shared<Bulk_quote>("book2", 50, 20, 0.25));
  for (const auto &e : vec)
    print_total(cout, *e, 30); // dynamic binding on net_price
}