//(a)
int calc(int &, int &) {}
int calc(const int &, const int &) {
} // legal: different in low-level const, which is not ignored
//(b)
int calc(char *, char *) {}
int calc(const char *, const char *) {} // legal: same reason as (a)
//(c)
int calc(char *, char *) {}
int calc(char *const, char *const) {} // illegal: top-level const is ignored