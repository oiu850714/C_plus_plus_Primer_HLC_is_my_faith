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

// 先說，這個程式跟 1.6 的那個行為有差異
// 對 Sales_item 做 >> 是要讀取 ISBN，賣出數量跟平均售價
// 對 Sales_item 做 << 會得到 ISBN，賣出數量，revenue 跟平均售價
// 可是這邊是讀取 ISBN，賣出數量跟 revenue 到 Sales_data
// 輸出也是直接出出 Sales_data 的 ISBN，賣出數量跟 revenue
// 可以看 Primer 給的 Sales_item.h 的 114行那個
// operator<<，他真的是輸出不一樣的東西

int main() {
  Sales_data current_transactions;

  if (std::cin >> current_transactions.bookNo >>
      current_transactions.units_sold >> current_transactions.revenue) {
    Sales_data new_transaction;
    while (std::cin >> new_transaction.bookNo >> new_transaction.units_sold >>
           new_transaction.revenue) {
      if (new_transaction.bookNo == current_transactions.bookNo) {
        current_transactions.units_sold += new_transaction.units_sold;
        current_transactions.revenue += new_transaction.revenue;
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