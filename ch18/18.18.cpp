#include <string>

struct T {
  std::string mem1;
  int mem2;
};

void swap(T v1, T v2) {
  using std::swap;
  swap(v1.mem1, v2.mem1);
  // because mem1 is class type, ADL will be applied and uses specific string
  // swap version

  // swap remaining members of type T
}

// void swap(T v1, T v2) {
//   using std::swap;
//   swap(v1.mem1, v2.mem1);
//   // built-in type will not trigger ADL and uses std::swap
//   //  swap remaining members of type T
// }

int main() {}