int main() {
  int i = 0;
  //(a)
  double *dp = &i; // illegal, i is not double and dp cannot point to i
  //(b)
  int *ip = i; // illegal, should add address-of operator on i
  //(c)
  int *p = &i; // legal
}