int main() {
  int i = 0, j = 0, k = 0;
  i != j < k;
  // < has higher precedence than !=
  // so i != j < k
  // is i != (j < k)
}