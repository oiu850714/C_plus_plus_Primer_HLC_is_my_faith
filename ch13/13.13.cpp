#include <iostream>
#include <vector>

struct X {
  X() { std::cout << "X()" << std::endl; }
  X(const X &) { std::cout << "X(const X&)" << std::endl; }
  X &operator=(const X &) {
    std::cout << "operator=(const X&)" << std::endl;
    return *this;
  }
  ~X() { std::cout << "~X()" << std::endl; }
};

X receive_X(X x) {
  std::cout << "receive_X:" << std::endl;
  std::cout << "return X:" << std::endl;
  return x;
}

X *new_X() {
  std::cout << "new_X:" << std::endl;
  X *ptr = new X;
  return ptr;
}

void reference_X(X &x) { std::cout << "reference_X:" << std::endl; }

int main() {
  X x1, x2;
  X X3 = receive_X(x1); // this line has feature called "copy elision". Remember
                        // the end of problem description:
                        // As you read the output, remember that the compiler
                        // can omit calls to the copy constructor.
  reference_X(x2);
  X *ptr = new_X();
  std::cout << "delete allocated X:" << std::endl;
  delete ptr;
  std::cout << "create container of X:" << std::endl;
  std::vector<X> vec(5);
  std::cout << "copy container of X:" << std::endl;
  std::vector<X> vec2 = vec;
}
// output:
// X()
// X()
// X(const X&)
// receive_X:
// return X:
// X(const X&)
// ~X()
// reference_X:
// new_X:
// X()
// delete allocated X:
// ~X()
// create container of X:
// X()
// X()
// X()
// X()
// X()
// copy container of X:
// X(const X&)
// X(const X&)
// X(const X&)
// X(const X&)
// X(const X&)
// ~X()
// ~X()
// ~X()
// ~X()
// ~X()
// ~X()
// ~X()
// ~X()
// ~X()
// ~X()
// ~X()
// ~X()
// ~X()