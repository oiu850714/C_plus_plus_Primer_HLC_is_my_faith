#include "../ch1/include/Sales_item.h"

using Sales_data = Sales_item;

bool fcn(const Sales_data *trans, Sales_data accum) {
  Sales_data item1(*trans), item2(accum);
  return item1.isbn() != item2.isbn();
} // accum, item1, item2's destructor call when fcn finishes