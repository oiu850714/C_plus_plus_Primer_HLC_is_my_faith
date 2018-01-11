int main() {
  //(a)
  int i, *const cp; // cp must be initialized
  //(b)
  int *p1, *const p2; // p2 must be initialized
  //(c)
  const int ic, &r = ic; // ic must be initialized
  //(d)
  const int *const p3; // p3 must be initialized
  //(e)
  const int *p; // legal, p can point to any const int
}