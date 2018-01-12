int main() {
  const int i = 42;
  auto j = i;        // j's type: int, value: 42
  const auto &k = i; // k's type: reference to const int(can omit "const" in
                     // base type), bind to i
  auto *p = &i;      // p's type: pointer to const int
  const auto j2 = i,
             &k2 = i; // j2's type: const int, value: 42; k2's type: reference
                      // to const int
}