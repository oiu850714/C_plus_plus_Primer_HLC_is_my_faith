int main() {
  int i = 0, &r = i;
  auto a = r; // a is an int (r is an alias for i, which has type int)
  const int ci = i, &cr = ci;
  auto b = ci;  // b is an int(top-level constin ciis dropped)
  auto c = cr;  // c is an int(cr is an alias for ciwhose constis top-level)
  auto d = &i;  // d is an int*(&of an intobject is int*)
  auto e = &ci; // e is const int*(&of a const object is low-level const)
  const auto f = ci; // deduced type ofciis int; f has type constint
  auto &g = ci;      // g is a const int& that is bound to ci
  // auto &h = 42;        // error: we can’t bind a plain reference to a
  // literal
  const auto &j = 42;  // ok: we can bind a constreference to a literal
  auto k = ci, &l = i; // k is int; lis
  // int &auto &m = ci, *p = &ci; // m is a const int&; p is a pointer to
  // constint  auto &n = i, *p2 = &ci;      // error: type deduced from i is
  // int; type deduced from &ci is constint

  a = 42; // a itself becomes 42
  b = 42; // b itself becomes 42
  c = 42; // c itself becomes 42
}

// Don't know what code I should write