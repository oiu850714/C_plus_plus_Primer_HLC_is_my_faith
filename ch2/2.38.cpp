int main() {
  int i1 = 0;
  const int i2 = 42;
  auto a1 = i1;
  decltype(i1) d1 = i1;
  // 2 lines above have same type
  auto a2 = i2;
  decltype(i2) d2 = i2;
  // 2 lines above have different type
}

// Reference:
// https://github.com/Mooophy/Cpp-Primer/tree/master/ch02#exercise-238