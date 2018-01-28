#include <fstream>
#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

std::ostream &print(std::ostream &output, const Sales_data &data) {
  output << data.bookNo << " " << data.units_sold << " " << data.revenue;
  return output;
}

std::istream &read(std::istream &is, Sales_data &data) {
  is >> data.bookNo >> data.units_sold >> data.revenue;
  return is;
}

int main(int argc, char **argv) {
  if (argc < 3) {
    std::cout << "please give input and output file name" << std::endl;
    return 1;
  }
  std::ifstream in(argv[1]);
  if (!in) {
    std::cout << "open input file failed" << std::endl;
    return 1;
  }

  std::ofstream out(argv[2]);
  if (!out) {
    std::cout << "open output file failed" << std::endl;
    return 1;
  }

  Sales_data current_transactions;

  if (read(in, current_transactions)) {
    Sales_data new_transaction;
    while (read(in, new_transaction)) {
      if (new_transaction.bookNo == current_transactions.bookNo) {
        current_transactions.units_sold += new_transaction.units_sold;
        current_transactions.revenue += new_transaction.revenue;
      } else {
        print(out, current_transactions) << std::endl;

        current_transactions = new_transaction;
      }
    }
    print(out, current_transactions) << std::endl;
  } else {
    std::cout << "No data?!\n";
    return 1;
  }

  return 0;
}