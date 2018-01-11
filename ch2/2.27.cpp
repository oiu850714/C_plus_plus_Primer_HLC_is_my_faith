int main() {
  //(a)
  int i = -1, &r = 0; // r cannot bind to literal
  //(b)
  int *const p2 = &i2; // if i2 is inr then legal
  //(c)
  const int i = -1, &r = 0; // legal
  //(d)
  const int *const p3 = &i2; // if i2 is int then legal
  //(e)
  const int *p1 = &i2; // if i2 is int then legal
  //(f)
  const int &const r2; // reference itselt cannot be declared as constant
  //(g)
  const int i2 = i, &r = i; // legal
}