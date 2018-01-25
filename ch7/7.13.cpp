#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

struct Sales_data;
// add class declaration to let function "read" see

Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
// add function "read" declaration to let Sales_data::Sales_data see

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

int main() {
  Sales_data total(cin);     // variable to hold the running sum
  if (cin) {                 // read the first transaction
    while (cin) {            // read the remaining transactions
      Sales_data trans(cin); // variable to hold data for the next transaction
      if (total.isbn() == trans.isbn()) // check the isbns
        total.combine(trans);           // update the running total
      else {
        print(cout, total) << endl; // print the results
        total = trans;              // process the next book
      }
    }
    // no need to print last transaction, because we now check cin first then
    // read data
    // if print last transaction, it will print defalut value
  } else {                       // there was no input
    cerr << "No data?!" << endl; // notify the user
  }
}

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