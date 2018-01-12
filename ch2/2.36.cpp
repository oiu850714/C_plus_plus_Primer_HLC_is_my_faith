int main() {
  int a = 3, b = 4;
  decltype(a) c = a;
  decltype((b)) d = a;
  ++c;
  ++d;
}
// type of a: int, value: 4
// type of b: int, value: 4
// type of c: int, value: 4
// type of d: int&, bind to a, value: 4