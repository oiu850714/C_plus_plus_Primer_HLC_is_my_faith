#include <iostream>
#include <string>

struct Sales_data;
// add class declaration to let function "read" see
std::istream &read(std::istream &is, Sales_data &data);
// add function "read" declaration to let Sales_data::Sales_data see
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

  Sales_data() = default;
  Sales_data(const std::string &s) : bookNo(s) {}
  Sales_data(const std::string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(n * p) {}
  Sales_data(std::istream &is) { read(is, *this); }
  Sales_data &combine(const Sales_data &rhs);
  std::string isbn() const { return bookNo; };
};

Sales_data &Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  return sum.combine(rhs);
}

std::ostream &print(std::ostream &os, const Sales_data &data) {
  os << data.bookNo << " " << data.units_sold << " " << data.revenue;
  return os;
}

std::istream &read(std::istream &is, Sales_data &data) {
  is >> data.bookNo >> data.units_sold >> data.revenue;
  return is;
}
