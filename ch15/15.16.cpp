#include "15.15.h"

class Bulk_limit : public Disc_quote {
public:
  Bulk_limit() = default;
  Bulk_limit(const std::string &book, double price, size_t qty, size_t lim,
             double dis);
  virtual double net_price(size_t n) const override;

private:
  size_t limit = 0;
};

Bulk_limit::Bulk_limit(const std::string &book, double price, size_t qty,
                       size_t lim, double dis)
    : Disc_quote(book, price, qty, dis), limit(lim) {}

double Bulk_limit::net_price(size_t n) const {
  if (n < quantity) {
    return n * price;
  } else if (n <= limit) {
    return n * (1 - discount) * price;
  } else {
    return (limit * (1 - discount) * price) + ((n - limit) * price);
  }
}