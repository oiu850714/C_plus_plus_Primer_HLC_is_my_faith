int main() {
  int *p = nullptr;
  if (p)
    ; // ... condition will be true if p is not nullptr
  if (*p)
    ; // ... condition will be true if the value of int to which p points to is
      // not 0
}