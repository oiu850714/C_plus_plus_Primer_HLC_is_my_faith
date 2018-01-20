int main() {
  char cval;
  int ival;
  unsigned int ui;
  float fval;
  double dval;

  //(a)
  cval = 'a' + 3; // 3 is int, so 'a' is converted to int; 'a'(int) + 3(int)
                  // then converted to char and assigned to cval
  //(b)
  fval = ui - ival * 1.0; // ui and ival converted to double, the exp on rhs of
                          // = then converted to float and assigned to fval
  //(c)
  dval = ui * fval; // ui converted to float, the result of float + float
                    // converted to double and assigned to dval
  //(d)
  cval = ival + fval + dval; // ival converted to float; (ival(float) +
                             // fval(float)) converted to double; result
                             // converted to char
}