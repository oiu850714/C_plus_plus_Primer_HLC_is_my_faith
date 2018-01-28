#include <vector>
using std::vector;
class NoDefault {
public:
  NoDefault(int i) {}
};

class C {
public:
  C() : n(87) {}

private:
  NoDefault n;
};

int main() {
  vector<NoDefault> vec1(10); // illegal: Nodefault has no default constructor,
                              // when declare a vector with one argument, it
                              // will default initialize its element
  vector<NoDefault> vec2(10, NoDefault(10)); // legal
}