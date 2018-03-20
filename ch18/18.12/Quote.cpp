#include "Quote.h"
#include <iostream>
#include <set>
#include <vector>

using std::ostream;
using std::multiset;
using std::endl;

namespace chapter_15 {

double Bulk_quote::net_price(size_t cnt) const {
  if (cnt >= quantity)
    return cnt * (1 - discount) * price;
  else
    return cnt * price;
}

// ex 15.26
Bulk_quote::Bulk_quote(const Bulk_quote &q)
    : Disc_quote(q) { /* all members defined in (indirect) base class */
  // std::cout << "Bulk_quote::copy_ctor\n";
}
Bulk_quote &Bulk_quote::operator=(const Bulk_quote &q) {
  Disc_quote::operator=(q); // strictly speaking, base doesn't allocate memory,
                            // doesn't need to handle self-assignment
  // std::cout << "Bulk_quote::operator=\n";
  return *this;
}
Bulk_quote::~Bulk_quote() { /* no work to do... */
  // std::cout << "Bulk_quote::dtor\n";
}

double print_total(ostream &os, const Quote &item, size_t n) {
  // depending on the type of the object bound to the item parameter
  // calls either Quote::net_price or Bulk_quote::net_price
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() // calls Quote::isbn
     << " # sold: " << n << " total due: " << ret << endl;
  return ret;
}

double Basket::total_receipt(ostream &os) const {
  double sum = 0.0; // holds the running total
  // iter refers to the first element in a batch of elements with the same ISBN
  // upper_bound returns an iterator to the element just past the end of that
  // batch
  for (auto iter = items.cbegin(); iter != items.cend();
       iter = items.upper_bound(*iter)) {
    // we know there's at least one element with this key in the Basket
    // print the line item for this book
    sum += print_total(os, **iter, items.count(*iter));
  }
  os << "Total Sale: " << sum << endl; // print the final overall total
  return sum;
}

} // namespace chapter_15