#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main() {
  Sales_data data1, data2;
  double price1, price2;
  std::cin >> data1.bookNo >> data1.units_sold >> price1;
  std::cin >> data2.bookNo >> data2.units_sold >> price2;

  data1.revenue = price1 * data1.units_sold;
  data2.revenue = price2 * data2.units_sold;

  if (data1.bookNo == data2.bookNo) {
    std::cout << data1.bookNo << " " << data1.units_sold + data2.units_sold
              << " " << data1.revenue + data2.revenue << std::endl;
    return 0;
  } else {
    std::cout << "ISBN not same\n";
    return 1;
  }
}