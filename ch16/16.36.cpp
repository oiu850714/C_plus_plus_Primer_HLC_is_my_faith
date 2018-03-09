// WTF is this sample code? so many errors lol. where is return type? assume
// return void

template <typename T> void f1(T, T);

template <typename T1, typename T2> void f2(T1, T2);

int i = 0, j = 42, *p1 = &i, *p2 = &j;

const int *cp1 = &i, *cp2 = &j;
int main() {
  //(a)
  f1(p1, p2);
  // T will be deduced to int*

  //(b)
  f2(p1, p2);
  // both T1 and T2 will be deduced to int*

  //(c)
  f1(cp1, cp2);
  // T will be deduced to const int*

  //(d)
  f2(cp1, cp2);
  // both T1 and T2 will be deduced to const int*

  //(e)
  f1(p1, cp1);
  // error: p1's type is int*, cp1's type is const int*, and low-level-const is
  // never ignored, so there is deduced-conflicting-types error

  //(e)
  f2(p1, cp1);
  // T1 will be deduced to int*, T2 will be deduced to const int*
}