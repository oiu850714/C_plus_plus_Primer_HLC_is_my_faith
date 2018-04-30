
#include "Sales_item.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>
using std::tuple;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::equal_range;
using std::istream;
using std::ostream;
using std::get;
using Sales_data = Sales_item;

using matches =
    tuple<vector<Sales_data>::size_type, vector<Sales_data>::const_iterator,
          vector<Sales_data>::const_iterator>;

vector<matches> findBook(const vector<vector<Sales_data>> &files,
                         const string &book) {
  vector<matches> ret;
  for (auto it = files.cbegin(); it != files.cend(); ++it) {
    auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
    if (found.first != found.second)
      ret.push_back({it - files.cbegin(), found.first, found.second});
  }
  return ret;
}

void reportResults(istream &in, ostream &os,
                   const vector<vector<Sales_data>> &files) {
  string s; // book to look for
  while (in >> s) {
    auto trans = findBook(files, s); // stores that sold this book
    if (trans.empty()) {
      cout << s << " not found in any stores" << endl;
      continue; // get the next book to look for
    }
    for (const auto &store : trans) // for every store with a sale
    {
      // get<n> returns the specified member from the tuple in store
      os << "store " << get<0>(store) << " sales: "
         << accumulate(get<1>(store), get<2>(store), Sales_data(s)) << endl;
    }
  }
}

int main() {
  // just divide input data in 17.4-Test.txt into four book stores
  vector<vector<Sales_data>> files{
      {Sales_data(std::cin), Sales_data(std::cin), Sales_data(std::cin)},
      {Sales_data(std::cin), Sales_data(std::cin), Sales_data(std::cin)},
      {Sales_data(std::cin), Sales_data(std::cin), Sales_data(std::cin)},
      {Sales_data(std::cin), Sales_data(std::cin), Sales_data(std::cin)}};
  reportResults(cin, cout, files);
}