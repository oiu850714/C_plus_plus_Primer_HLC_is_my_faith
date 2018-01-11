int main() {
  int i = 42;
  void *p = &i;  // void pointer can point to objects of any type
  long *lp = &i; // but pointer to long cannot point to int
}

/*
 * int main() {
 *   int i = 42;
 *   void *p = &i;  // void pointer can point to objects of any type
 *   long *lp = &i; // but pointer to long cannot point to int
 * }
 * But if you compile this code by gcc, it will only output warning!
 *
 */