#include "15.26.h"
#include <iostream>

using std::cout;

int main() {
  Quote q1;
  Quote q2(q1);
  cout << "-------------------\n";
  Bulk_quote bq1;
  Bulk_quote bq2(bq1);
  cout << "-------------------\n";
  q1 = q2;
  cout << "-------------------\n";
  q1 = bq1;
  cout << "-------------------\n";
  bq1 = bq2;
  cout << "-------------------\n";
}