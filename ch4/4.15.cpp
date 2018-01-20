int main() {
  double dval;
  int ival;
  int *pi;
  // dval = ival = pi = 0;
  // there is no conversion between int* and int
  // correct:
  pi = nullptr;
  dval = ival = 0;
}