int main() {
  int i = 0;
  const int v2 = 0;        // top level const
  int v1 = v2;             // both not
  int *p1 = &v1, &r1 = v1; // p1 and r1 both not
  const int *p2 = &v2, *const p3 = &i,
            &r2 = v2; // p2 low level, p3 both, r2 low level

  r1 = v2; // lega: v2's top level const is ignored
  p1 = p2; // illegal: p2's low level const is not ignored, hence p2 cannot be
           // assigned
  // to p1
  p2 = p1; // legal: though p1 and p2's low level const are different, but
           // p1(non const low level) can be assigned to p2(const low level)
  p1 = p3; // illegal: like example above but p3(const low level) cannot be
           // assigned to p1(non const low level)
  p2 = p3; // legal: both const low level
}