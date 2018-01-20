int main() {
  int a = 94, b = 87;
  a &&b;  // only when a is true is b evaluated
  a || b; // only when a is false is b evaluated
  // Moreover, the right operand is evaluated if and only if the left operand
  // does not determine the result.
  a == b; // what... the order a and b being evaluated is undefined
}

// SEE: https://github.com/Mooophy/Cpp-Primer/tree/master/ch04#exercise-48
