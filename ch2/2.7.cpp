int main() {
  //(a)
  "Who goes with F\145rgus?\012"; // value is "Who goes with Fergus?(new
                                  // line)\0" type is array of chars, please
                                  // refer to ascii table
  //(b)
  3.14e1L; // value is 31.4, not 3.14; type is long double
  //(c)
  1024f; // invalid literal, f can be suffixed on floating point literals
  //(d)
  3.14L; // value is 3.14; type is long double
}