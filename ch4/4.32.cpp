int main() {

  constexpr int size = 5;
  int ia[size] = {1, 2, 3, 4, 5};
  for (int *ptr = ia, ix = 0; ix != size && ptr != ia + size;
       ++ix, ++ptr) { /* .. . */
  }
  // ix and ptr have same function: go through the array
  // just choose one of then
  // SEE: https://github.com/Mooophy/Cpp-Primer/tree/master/ch04#exercise-432
}