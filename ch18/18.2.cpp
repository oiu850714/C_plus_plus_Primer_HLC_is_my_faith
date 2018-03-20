void exercise(int *b, int *e) {
  vector<int> v(b, e);
  int *p = new int[v.size()];
  ifstream in("ints");
  // exception occurs here

  // the object to which p allocates will be leaked
}