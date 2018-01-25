#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

  Sales_data &combine(const Sales_data &rhs);
  std::string isbn() const { return bookNo; };
};

Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, const Sales_data &);

int main() {
  Sales_data current_transactions;

  if (read(std::cin, current_transactions)) {
    Sales_data new_transaction;
    while (std::cin >> new_transaction.bookNo >> new_transaction.units_sold >>
           new_transaction.revenue) {
      if (current_transactions.isbn() == new_transaction.isbn()) {
        current_transactions.combine(new_transaction);
      } else {
        print(std::cout, current_transactions) << std::endl;

        current_transactions = new_transaction;
      }
    }
    print(std::cout, current_transactions) << std::endl;
  } else {
    std::cout << "No data?!\n";
    return 1;
  }

  return 0;
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
