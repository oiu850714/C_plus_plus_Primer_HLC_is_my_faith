#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main() {
  Sales_data new_data;
  std::string isbn;
  unsigned total_sold = 0;
  double total_revenue = 0;
  double new_price = 0;
  while (std::cin >> new_data.bookNo >> new_data.units_sold >> new_price) {
    if (isbn != "" && new_data.bookNo != isbn) {
      std::cout << "Book number not same.\n";
      return 1;
    } else if (isbn == "") {
      isbn = new_data.bookNo;
    }

    total_sold += new_data.units_sold;
    total_revenue += new_data.units_sold * new_price;
  }

  std::cout << isbn << " total sold: " << total_sold
            << ", total revenue: " << total_revenue << std::endl;
  return 0;
}