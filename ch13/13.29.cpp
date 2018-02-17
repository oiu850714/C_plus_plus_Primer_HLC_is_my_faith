inline void swap(HasPtr &lhs, HasPtr &rhs) {
  using std::swap;
  swap(lhs.ps, rhs.ps); // swap the pointers, not the string data
  swap(lhs.i, rhs.i);   // swap the int members
}

// swap(lhs.ps, rhs.ps) matches swap(std::string*, std::string*);
// swap(lhs.i, rhs.i) matches swap(int*, int*);
// Both will be specialized(See ch16) by compiler, and are different from
// swap(HasPtr&, HasPtr&);, so swap(HasPtr &lhs, HasPtr &rhs) will not recurse.