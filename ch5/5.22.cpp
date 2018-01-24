extern int get_size();
/*
int main() {
begin:
  int sz = get_size();
  if (sz <= 0) {
    goto begin;
  }
}
*/

int main() {
  int sz = 0;
  while ((sz = get_size()) <= 0)
    ;
}