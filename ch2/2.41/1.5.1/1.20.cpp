#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main() {
  Sales_data data;
  double price = 0;
  while (std::cin >> data.bookNo >> data.units_sold >> price) {
    data.revenue = price * data.units_sold;
    std::cout << data.bookNo << " " << data.units_sold << " " << data.revenue
              << std::endl;
  }
  return 0;
}
