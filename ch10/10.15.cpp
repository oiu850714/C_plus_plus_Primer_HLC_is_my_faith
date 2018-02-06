int main() {
  int i = 87;
  auto captureAdd = [i](int j) { return i + j; };
}