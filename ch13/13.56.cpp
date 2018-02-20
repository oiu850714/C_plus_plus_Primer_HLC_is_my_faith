// SEE: https://github.com/Mooophy/Cpp-Primer/tree/master/ch13#exercise-1356
// ret is lvalue, so ret.sorted(); will match Foo::sorted() const &; it will
// recurse until stackoverflow