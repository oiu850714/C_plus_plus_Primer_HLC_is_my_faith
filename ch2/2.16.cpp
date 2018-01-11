int main() {
  int i = 0, &r1 = i;
  double d = 0, &r2 = d;
  //(a)
  r2 = 3.14159; // valid: d = 3.14159
  //(c)
  i = r2; // valid: i = d, now i = 3
  //(b)
  r2 = r1; // valid: d = i, now d = 0.0
  //(d)
  r1 = d; // valid: i = d, now i = 0
}