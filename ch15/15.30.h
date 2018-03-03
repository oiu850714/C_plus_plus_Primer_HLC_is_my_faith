#ifndef _15_30_H_
#define _15_30_H_

#include <iostream>
#include <memory>
#include <set>
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
  Quote(const Quote &q)
      : bookNo(q.bookNo), price(q.price){
                              // std::cout << "Quote::copy_ctor\n";
                          };
  Quote &operator=(const Quote &q) {
    if (this != &q) {
      bookNo = q.bookNo;
      price = q.price;
    }
    // std::cout << "Quote::operator=\n";
    return *this;
  }
  virtual ~Quote() {
    // std::cout << "Quote::dtor\n";
  } // dynamic binding for the destructor

  // ex 15.30
  virtual Quote *clone() const & { return new Quote(*this); }
  virtual Quote *clone() && { return new Quote(std::move(*this)); }

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

  // ex 15.26
  Bulk_quote(const Bulk_quote &);
  Bulk_quote &operator=(const Bulk_quote &);
  ~Bulk_quote();

  // ex 15.30
  Bulk_quote *clone() const & override { return new Bulk_quote(*this); }
  Bulk_quote *clone() && override { return new Bulk_quote(std::move(*this)); }
};

// ex 15.30
class Basket {
public:
  // Basket uses synthesized default constructor and copy-control members
  void add_item(const Quote &sale) {
    items.insert(std::shared_ptr<Quote>(sale.clone()));
  } // copy the given object
  void add_item(Quote &&sale) {
    items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
  } // move the given object
  // prints the total price for each book and the overall total for all items in
  // the basket
  double total_receipt(std::ostream &) const;

private:
  // function to compare shared_ptrs needed by the multiset member
  static bool compare(const std::shared_ptr<Quote> &lhs,
                      const std::shared_ptr<Quote> &rhs) {
    return lhs->isbn() < rhs->isbn();
  }
  // multiset to hold multiple quotes, ordered by the compare member
  std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};

#endif
