int main() {
  //(a)
  int double = 3.14; // invalid: identifier collides with keywords
  //(b)
  int _; // valid
  //(c)
  int catch - 22; // invalid: identifier cannot use hyphen
  //(d)
  int 1_or_2 = 1; // invalid: identifier cannot start with digits
  //(e)
  double Double = 3.14; // valid
}