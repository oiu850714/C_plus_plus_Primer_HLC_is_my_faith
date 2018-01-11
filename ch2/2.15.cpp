int main() {
  //(a)
  int ival =
      1.01; // valid: ordinary declaration, although narrowing down 1.01 to 1
  //(b)
  int &rval1 = 1.01; // invalid: 1.01 is not an (object)lvalue
  //(c)
  int &rval2 = ival; // valid: bind rval2 to ival
  //(d)
  int &rval3; // invalid: a reference must be initialized
}