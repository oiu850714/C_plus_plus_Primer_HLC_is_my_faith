int main() {
  bool flag;
  short sval;
  int ival;
  long lval;
  float fval;
  char cval;
  unsigned short usval;
  unsigned int uival;
  unsigned long ulval;
  double dval;
  //(a)
  if (fval) // converted to bool
    ;
  //(b)
  dval = fval + ival; // ival converted to float, fval(float) + ival(float)
                      // converted to double and is then assigned to dval
  //(c)
  dval + ival *cval; // cval converted to int, ival(int) + cval(int) converted
                     // to double
}