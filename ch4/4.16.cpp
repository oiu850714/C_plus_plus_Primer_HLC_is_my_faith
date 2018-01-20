extern int *getPtr();
int main() {
  int i = 0, *p = nullptr;
  //(a)
  if (p = getPtr() !=
          0) // Programmer may want to test whether p is nullptr,
             // but he or she should use parentheses at (p =
             // getPtr()) because assignment has lower precedence
             // than relational operator
             // but p cannot be assigned from bool so it will not compile lol
    ;
  //(b)
  if (i = 1024) // Programmer may want to test whether i is equal to 1024
                // but he use assignment. He or She should use "i == 1024"
    ;
}