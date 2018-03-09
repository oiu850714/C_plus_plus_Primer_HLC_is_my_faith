template <typename T> T calc(T, int);
template <typename T> T fcn(T, T);

double d;
float f;
char c;

int main() {
  //(a)
  calc(c, 'c');
  // legal: T is char, and second argument, 'c', will be promoted to int

  //(b)
  calc(d, f);
  // legal: T is double, and second argument, f, will be converted(narrow
  // downed) to int

  //(c)
  fcn(c, 'c');
  // legal: T is char; note that second argument 'c' will not cause any
  // conversion

  //(d)
  fcn(d, f);
  // illegal: deduced-conflicting-types error, d will be deduced to double, but
  // f will be deduced to float
}