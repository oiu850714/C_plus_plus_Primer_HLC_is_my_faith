#include "15.26.h"
#include <iostream>

double Bulk_quote::net_price(size_t cnt) const {
  if (cnt >= quantity)
    return cnt * (1 - discount) * price;
  else
    return cnt * price;
}

// ex 15.26
Bulk_quote::Bulk_quote(const Bulk_quote &q)
    : Disc_quote(q) { /* all members defined in (indirect) base class */
  std::cout << "Bulk_quote::copy_ctor\n";
}
Bulk_quote &Bulk_quote::operator=(const Bulk_quote &q) {
  Disc_quote::operator=(q); // strictly speaking, base doesn't allocate memory,
                            // doesn't need to handle self-assignment
  std::cout << "Bulk_quote::operator=\n";
  return *this;
}
Bulk_quote::~Bulk_quote() { /* no work to do... */
  std::cout << "Bulk_quote::dtor\n";
}