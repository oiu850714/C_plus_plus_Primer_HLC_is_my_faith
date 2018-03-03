#include "15.5.h"
#include <string>

Bulk_quote::Bulk_quote(const std::string &book, double p, std::size_t qty,
                       double disc)
    : Quote(book, p), min_qty(qty), discount(disc){
                                        // as before
                                    };

// if the specified number of items are purchased, use the discounted price
double Bulk_quote::net_price(size_t cnt) const {
  if (cnt >= min_qty)
    return cnt * (1 - discount) * price;
  else
    return cnt * price;
}