#include <iostream>
#include <string>

class Sales_data;
// add class declaration to let function "read" see
std::istream &read(std::istream &is, Sales_data &data);
// add function "read" declaration to let Sales_data::Sales_data see
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);

class Sales_data {

  friend std::istream &read(std::istream &is, Sales_data &data);
  friend Sales_data add(const Sales_data &, const Sales_data &);
  friend std::ostream &print(std::ostream &, const Sales_data &);

private:
  std::string bookNo;
  unsigned units_sold;
  double revenue;
  // CHANGE HERE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  inline double avg_price() const {
    return units_sold ? revenue / units_sold : 0;
  }

public:
  Sales_data(const std::string &s, unsigned n, double p) // delegated-to cstr
      : bookNo(s), units_sold(n), revenue(n * p) {}
  Sales_data(const std::string &s = "")
      : Sales_data(s, 0, 0.0) {}                // delegating cstr
  Sales_data(std::istream &is) : Sales_data() { // delegating cstr
    read(is, *this);
  }
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
  os << data.bookNo << " " << data.units_sold << " " << data.revenue << " "
     << data.avg_price();
  return os;
}

std::istream &read(std::istream &is, Sales_data &data) {
  double price = 0.0;
  is >> data.bookNo >> data.units_sold >> price;
  data.revenue = price * data.units_sold;
  return is;
}

using std::cin;

Sales_data first_item(cin); // Sales_data(std::istream &is);
int main() {
  Sales_data next; // Sales_data(const std::string &s = "");
  // bookNo = "", units_sold = 0, revenue = 0;
  Sales_data last("9-999-99999-9"); // Sales_data(const std::string &s = "");
  // bookNo = "9-999-99999-9", units_sold = 0, revenue = 0;
}