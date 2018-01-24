void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);

int main() {
  //(a)
  f(2.56, 42);
  // viable functions: f(int, int); and f(double, double = 3.14);
  // f(double, double = 3.14) match 2.56 better than other viable functions
  // f(int, int) match 42 betther than other viable functions
  // so this is an ambiguous call

  //(b)
  f(42);
  // viable functions: f(int); and f(double, double = 3.14);
  // f(int) match 42 better than other viable functions
  // not ambiguous call

  //(c)
  f(42, 0);
  // by same rule, f(int, int) is best match, no ambiguous
  //(d)
  f(2.56, 3.14);
  // f(double, double = 3.14) is best match, no ambiguous
}