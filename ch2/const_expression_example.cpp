
int main() {
  const int max_files = 20;        // max_files is a constant expression
  const int limit = max_files + 1; // limitis a constant expression
  int staff_size = 27;             // staff_size is not a constant expression
  const int sz = get_size();       // sz is "not" a constant expression
  /*
   * Although staff_size is initialized from a literal,
   * it is not a constant expression because it is a plain int,
   * not a const int.On the other hand, even though sz is a const,
   * the value of its initializer is not known until run time.Hence,
   * sz is not a constant expression.
   */
}