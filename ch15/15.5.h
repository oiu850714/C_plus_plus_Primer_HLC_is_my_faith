#ifndef _15_5_H_
#define _15_5_H_

#include <string>

class Quote {
public:
  Quote() = default; // = default see § 7.1.4 (p. 264)
  Quote(const std::string &book, double sales_price)
      : bookNo(book), price(sales_price) {}
  std::string isbn() const { return bookNo; }
  // returns the total sales price for the specified number of items
  // derived classes will override and apply different discount algorithms
  virtual double net_price(std::size_t n) const { return n * price; }
  virtual ~Quote() = default; // dynamic binding for the destructor
private:
  std::string bookNo; // ISBN number of this item
protected:
  double price = 0.0; // normal, undiscounted price
};

class Bulk_quote : public Quote { // Bulk_quote inherits from Quote
public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double p, std::size_t qty, double disc);
  // overrides the base version in order to implement the bulk purchase
  // discount policy
  double net_price(std::size_t) const override;

private:
  std::size_t min_qty = 0; // minimum purchase for the discount to apply
  double discount = 0.0;   // fractional discount to apply
};

#endif
