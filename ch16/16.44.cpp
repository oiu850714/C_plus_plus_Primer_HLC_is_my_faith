template <typename T> void g(T val);
template <typename T> void g2(const T &val);
int i = 0;
const int ci = i;
int main() {
  //(a)
  g(i);  // g<int>(int val);
  g2(i); // g2<int>(const int &val);

  //(b)
  g(ci); // g<int>(int val);
  // const on ci is ignored
  g2(ci); // g2<int>(const int &val);
  // note that template argument T is int, not const int

  //(c)
  g(i * ci);  // g<int>(int val);
  g2(i * ci); // g2<int>(const int &val);
  // note that template argument T is int, not const int
}