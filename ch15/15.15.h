#ifndef _15_15_H_
#define _15_15_H_

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

class Disc_quote : public Quote {
public:
  Disc_quote() = default;
  Disc_quote(const std::string &book, double price, std::size_t qty,
             double disc)
      : Quote(book, price), quantity(qty), discount(disc) {}
  virtual double net_price(std::size_t n) const = 0;

protected:
  std::size_t quantity = 0;
  double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double price, std::size_t qty,
             double disc)
      : Disc_quote(book, price, qty, disc) {}
  virtual double net_price(std::size_t) const override;
};

#endif