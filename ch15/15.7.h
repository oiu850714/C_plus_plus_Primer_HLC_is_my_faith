#ifndef _15_7_H_
#define _15_7_H_

#include "15.5.h"
#include <string>

class Bulk_limit : public Quote {
public:
  Bulk_limit() = default;
  Bulk_limit(const std::string &book, double price, size_t qty, size_t lim,
             double dis);
  virtual double net_price(size_t n) const;

private:
  size_t limit = 0;
  size_t min_qty = 0;
  double discount = 0.0;
};

#endif