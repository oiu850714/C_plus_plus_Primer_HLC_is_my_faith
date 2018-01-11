int main() {
  int i = 0;
  const int v2 = 0;        // top level const
  int v1 = v2;             // both not
  int *p1 = &v1, &r1 = v1; // p1 and r1 both not
  const int *p2 = &v2, *const p3 = &i,
            &r2 = v2; // p2 low level, p3 both, r2 low level
}