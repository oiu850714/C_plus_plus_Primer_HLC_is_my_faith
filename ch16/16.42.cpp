template <typename T> void g(T &&val);
int i = 0;
const int ci = i;
int main() {
  //(a)
  g(i); // g<int&>(int& val);

  //(b)
  g(ci); // g<const int&>(const int& val);

  //(c)
  g(i * ci); // g<int>(int&& val);

  // ex 16.43
  g(i = ci);
  // assignment returns lvalue, so same as (a)
}