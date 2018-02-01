bool b() {
  int *p = new int; // .. .
  return p;
}
// int* will be converted to bool, and when b return, no pointer points to
// object p had newed, memory leaked