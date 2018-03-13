#include <utility>

template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2) {
  f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void val1_val2(int i, int j) {
  i++;
  j++;
}

void val1_lref2(int i, int &j) {
  i++;
  j++;
}

void val1_rref2(int i, int &&j) {
  i++;
  j++;
}

#include <iostream>
int main() {
  int i = 10;
  int j = 100;

  flip(val1_val2, i, j); // t1/t2 will bind i/j, but f only copies t1/t2, so f
                         // will not change t1/t2, which leaves i/j unchanged
  std::cout << i << " " << j << std::endl;

  flip(val1_lref2, i, j);
  std::cout << i << " " << j << std::endl; // i will be changed

  flip(val1_rref2, i + j, i + j); // need to pass rvalue, and pass rvalue,
                                  // std::forward worked correctly
  std::cout << i << " " << j << std::endl;
}