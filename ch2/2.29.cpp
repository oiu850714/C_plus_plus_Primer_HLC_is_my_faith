int main() {
  int i;
  const int ic = 0;
  int *p1;
  int *const p2 = &i;
  const int *const p3 = &i;
  //(a)
  i = ic; // legal: just copy const int ic's value to i
  //(c)
  p1 = &ic; // illegal: cannot use pointer to int to point to const int
  //(e)
  p2 = p1; // illegal: p2 is const pointer, it cannot be modified
  //(b)
  p1 = p3; // illegal: p3 is const pointer to "const int", and p1 is pointer to
           // "int", and p1 cannot pointer to const int
  //(d)
  p3 = &ic; // illegal: p3 is const pointer, it cannot be modified
  //(f)
  ic = *p3; // illegal: ic is const int, it cannot be modified
}