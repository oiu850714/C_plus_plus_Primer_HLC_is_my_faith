#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main() {
  Sales_data current_data;
  Sales_data new_data;
  double current_price = 0;
  double new_price = 0;
  int count = 1;
  if (std::cin >> current_data.bookNo >> current_data.units_sold >>
      current_price) {
    current_data.revenue = current_price * current_data.units_sold;
    while (std::cin >> new_data.bookNo >> new_data.units_sold >> new_price) {
      if (new_data.bookNo == current_data.bookNo) {
        current_data.units_sold += new_data.units_sold;
        current_data.revenue += new_data.units_sold * new_price;
        count++;
      } else {
        std::cout << current_data.bookNo
                  << "total sold: " << current_data.units_sold
                  << ", total revenue: " << current_data.revenue << std::endl;
        std::cout << "transaction count: " << count << std::endl;
        count = 1;
        current_data.bookNo = new_data.bookNo;
        current_data.units_sold = new_data.units_sold;
        current_data.revenue = new_price * new_data.units_sold;
      }
    }

    std::cout << current_data.bookNo
              << " total sold: " << current_data.units_sold
              << ", total revenue: " << current_data.revenue << std::endl;
    std::cout << "transaction count: " << count << std::endl;
    // output last data, because not learned how to write functions so I didn't
    // put lines above into function
  } else {
    std::cout << "No data?!\n";
    return 1;
  }

  return 0;
}