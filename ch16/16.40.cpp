template <typename It> auto fcn3(It beg, It end) -> decltype(*beg + 0) {
  // process the range
  return *beg; // return a copy ofan element from the range
}
// legel, but the elements to which It points to must have
// operator+(element_type, int); return type is this operator+'s return type