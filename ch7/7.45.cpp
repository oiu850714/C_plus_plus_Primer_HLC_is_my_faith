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
  vector<C> vec(10);
  // legal, because C's default constructor exists, and it explicitly
  // initializes it NeDefault member
}