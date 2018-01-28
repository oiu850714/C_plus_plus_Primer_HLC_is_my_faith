Sales_data(std::istream &is = std::cin) { read(is, *this); }
// If we change istream version constructor to this, it will be illegal when
// defining an Sales_data object with no parameter. It's an ambiguous call.
