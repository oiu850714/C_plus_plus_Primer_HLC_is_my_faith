int main() {
  int i = 0;
  if (42 = i) // ...
    ;         // illegal, lhs of assignment must be modifiable lvalue
  if (i = 42) // ...
    ; // legal, assign 42 to i and then convert i to bool, true if i != 0
}