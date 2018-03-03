#include "15.7.h"

#include <string>

Bulk_limit::Bulk_limit(const std::string &book, double price, size_t qty,
                       size_t lim, double dis)
    : Quote(book, price), limit(lim), min_qty(qty), discount(dis) {}

double Bulk_limit::net_price(size_t n) const {
  if (n < min_qty) {
    return n * price;
  } else if (n <= limit) {
    return n * (1 - discount) * price;
  } else {
    return (limit * (1 - discount) * price) + ((n - limit) * price);
  }
}
