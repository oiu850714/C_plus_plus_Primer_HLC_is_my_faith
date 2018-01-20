int main() {
  int someValue = 0, x = 94, y = 87;
  someValue ? ++x, ++y : --x, --y;
  // equivalent
  (someValue ? ++x, ++y : --x), --y;
}