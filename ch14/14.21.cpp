#include <iostream>
#include <string>

class Sales_data;
std::istream &read(std::istream &is, Sales_data &data);
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);

// ex 14.2
std::istream &operator>>(std::istream &, Sales_data &);
std::ostream &operator<<(std::ostream &, const Sales_data &);
Sales_data operator+(const Sales_data &, const Sales_data &);

class Sales_data {

  friend std::istream &read(std::istream &is, Sales_data &data);
  friend Sales_data add(const Sales_data &, const Sales_data &);
  friend std::ostream &print(std::ostream &, const Sales_data &);

  // ex 14.2
  friend std::istream &operator>>(std::istream &, Sales_data &);
  friend std::ostream &operator<<(std::ostream &, const Sales_data &);
  friend Sales_data operator+(const Sales_data &, const Sales_data &);

private:
  std::string bookNo;
  unsigned units_sold;
  double revenue;
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

  // ex 14.2
  Sales_data &operator+=(const Sales_data &);
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

// ex 14.6
std::ostream &operator<<(std::ostream &os, const Sales_data &data) {
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

// ex 14.9
std::istream &operator>>(std::istream &is, Sales_data &data) {
  double price; // no need to initialize; we’ll read into price before we use it
  is >> data.bookNo >> data.units_sold >> price;
  if (is) // check that the inputs succeeded
    data.revenue = data.units_sold * price;
  else
    data = Sales_data(); // input failed: give the object the default state
  return is;
}

// ex 14.21
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data data = lhs;
  data.units_sold += rhs.units_sold;
  data.revenue += rhs.revenue;
  return data;
}

// ex 14.21
Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
  *this =
      *this + rhs; // rhs is temporary Sales_data object, although being moved
  return *this;
}