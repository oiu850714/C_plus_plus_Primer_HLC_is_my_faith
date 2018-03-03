#include "15.30.h"
#include <iostream>

using std::cout;

int main() {
  Quote q1("book1", 50);
  Bulk_quote q2("book2", 50, 4, 0.25);

  Basket basket;
  basket.add_item(q1);
  basket.add_item(q1);
  basket.add_item(q1);
  // 3 "book1"
  basket.add_item(q2);
  basket.add_item(q2);
  basket.add_item(q2);
  basket.add_item(q2);
  basket.add_item(q2);
  // 5 "book2"

  basket.add_item(Quote("book3", 60));
  basket.add_item(Quote("book3", 60));
  // 2 "book3"

  basket.add_item(Bulk_quote("book4", 60, 5, 0.20));
  basket.add_item(Bulk_quote("book4", 60, 5, 0.20));
  basket.add_item(Bulk_quote("book4", 60, 5, 0.20));
  basket.add_item(Bulk_quote("book4", 60, 5, 0.20));
  basket.add_item(Bulk_quote("book4", 60, 5, 0.20));
  // 5 "book4"

  cout << "------start of total_receipt-------\n";
  basket.total_receipt(cout);
  cout << "--------end of total_receipt-------\n";
}