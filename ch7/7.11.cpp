#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

  Sales_data() = default;
  Sales_data(const std::string &s) : bookNo(s) {}
  Sales_data(const std::string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(n * p) {}
  Sales_data(std::istream &is);
  Sales_data &combine(const Sales_data &rhs);
  std::string isbn() const { return bookNo; };
};

Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

int main() {
  Sales_data data_defalut;
  Sales_data data_string("hsilu");
  Sales_data data_complete("hsilu", 1970, 216);
  Sales_data data_get_from_input(std::cin);

  print(std::cout, data_defalut) << std::endl;
  print(std::cout, data_string) << std::endl;
  print(std::cout, data_complete) << std::endl;
  print(std::cout, data_get_from_input) << std::endl;
  return 0;
}

Sales_data::Sales_data(std::istream &is) { read(is, *this); }

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
