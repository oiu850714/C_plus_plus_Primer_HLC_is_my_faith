int main() {
  int a = 3, b = 4;
  decltype(a) c = a;
  decltype(a = b) d = a;
  // 操! 糞扣! 上面的 a = b 不會執行，因為在 decltype 內的 operand 不會被執行
  // a = 3, b = 4, c = 3, d = 3
  // a, b is int; c is int, d is int&
}