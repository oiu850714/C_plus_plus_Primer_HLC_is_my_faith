#include "../ch1/include/Sales_item.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

using std::sort;
using std::find_if;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::accumulate;

bool compraeSales_item(const Sales_item &item1, const Sales_item &item2) {
  return item1.isbn() < item2.isbn();
}

int main() {
  vector<Sales_item> vec((istream_iterator<Sales_item>(cin)),
                         (istream_iterator<Sales_item>()));
  sort(vec.begin(), vec.end(), compraeSales_item);
  ostream_iterator<Sales_item> os_iter(cout, "\n");

  for (auto group_begin = vec.cbegin(), group_end = group_begin;
       group_begin != vec.cend(); group_begin = group_end) {
    group_end =
        find_if(group_begin, vec.cend(), [group_begin](const Sales_item &item) {
          return item.isbn() != group_begin->isbn();
        });
    os_iter =
        accumulate(group_begin, group_end, Sales_item(group_begin->isbn()));
  }
}