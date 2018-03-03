#ifndef _15_26_H_
#define _15_26_H_

#include <iostream>
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

  // ex 15.26
  Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) {
    std::cout << "Quote::copy_ctor\n";
  };
  Quote &operator=(const Quote &q) {
    if (this != &q) {
      bookNo = q.bookNo;
      price = q.price;
    }
    std::cout << "Quote::operator=\n";
    return *this;
  }
  virtual ~Quote() {
    std::cout << "Quote::dtor\n";
  } // dynamic binding for the destructor

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
  // ex 15.27
  Bulk_quote() =
      default; // self defined copy ctor, so need to defined default ctor
  using Disc_quote::Disc_quote;
  // this cstr will using inherited ctor
  /*
  Bulk_quote(const std::string &book, double price, std::size_t qty,
             double disc)
      : Disc_quote(book, price, qty, disc) {}
  */
  virtual double net_price(std::size_t) const override;

  // ex 15.26
  Bulk_quote(const Bulk_quote &); // copy ctor not inherited
  Bulk_quote &operator=(const Bulk_quote &);
  ~Bulk_quote();
};

#endif