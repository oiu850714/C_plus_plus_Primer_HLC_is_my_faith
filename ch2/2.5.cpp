
int main() {
  // (a)
  'a', L'a', "a", L"a"; // 'a' is char, L'a' is wchar_t, "a" is array of char,
                        // L"a" is array of wchar_t
  // (b)
  10, 10u, 10L, 10uL, 012, 0xC; // 10 is int, 10u is unsigned int, 10L is long,
                                // 10uL is unsigned long, 012 is unsigned int,
                                // 0xC is unsigned int
                                // but visual studio code show 012 and 0xC is
                                // int, different from Primer's definition
  // (c)
  3.14, 3.14f, 3.14L; // 3.14 is double, 3.14f is float, 3.14L is long double
  // (d)
  10, 10u, 10.,
      10e-2; // 10 is int, 10u is unsigned int, 10. is double, 10e-2 is double
}