template <class T> int compare(const T &, const T &);
int main() {
  //(a)
  compare("hi", "world");
  // illegal: function parameter in compare is const reference, so string
  // literal will not be converted to char*; and the type of "h1" and "world"
  // are different(const char[3] and const char[6]), so it causes
  // deduced-conflicting-types error

  //(b)
  compare("bye", "dad");
  // legal, because the types of "bye" and "dad" are the same(const char[4]),
  // and T is char[4]
}