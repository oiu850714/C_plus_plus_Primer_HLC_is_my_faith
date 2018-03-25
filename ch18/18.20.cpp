namespace primerLib {
void compute();
void compute(const void *);
} // namespace primerLib
using primerLib::compute;
void compute(int);
void compute(double, double = 3.4);
void compute(char *, char * = 0);
void f() {
  compute(0);
  // candidates:
  // all five "compute" functions
  //
  // viable functions:
  // primberLib::compute(const void*), need conversion: int -> const void*
  // ::compute(int), exact match
  // ::compute(double, double = 3.4), need conversion: int -> double
  // ::compute(char *, char * = 0), need conversion: int -> char*
}

int main() {
  using primerLib::compute;
  // using declaration will hide names in global scope!

  compute(0);
  // if using declaration is located in main and not in global, candidate
  // functions become all three "compute" in global scope when calling
  // "compute" at f

  // and in main, if main calls "compute", candidates function two "compute"s in
  // primerLib, viable function is primerLib::compute(const void *) only
}