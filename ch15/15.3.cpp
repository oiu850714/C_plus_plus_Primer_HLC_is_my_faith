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

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;
// calculate and print the price for the given number of copies, applying any
// discounts
double print_total(ostream &os, const Quote &item, size_t n) {
  // depending on the type of the object bound to the item parameter
  // calls either Quote::net_price or Bulk_quote::net_price
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() // calls Quote::isbn
     << " # sold: " << n << " total due: " << ret << endl;
  return ret;
}