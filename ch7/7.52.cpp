#include <string>

struct Sales_data {
  std::string bookNo;
  // unsigned units_sold = 0;
  unsigned units_sold;
  // double revenue = 0.0;
  double revenue;
  // aggregate class cannot have in-class initailizer
};

int main() { Sales_data item = {"978-0590353403", 25, 15.99}; }