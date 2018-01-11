int main() {
  //(a)
  const int buf; // illegal: const must be initiailized
  //(b)
  int cnt = 0;
  //(c)
  const int sz = cnt;
  //(d)
  ++cnt;
  ++sz; // illegal: const cannot be modified
  double dval = 3.14;
}