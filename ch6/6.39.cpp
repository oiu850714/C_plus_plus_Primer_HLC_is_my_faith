//(a)
int calc(int, int);             // { return 94; }
int calc(const int, const int); // { return 87; }
// SEE: https://github.com/Mooophy/Cpp-Primer/issues/487
// 只是給 declaration 不會噴 error，就好像你打了一百次 void f(); 也不會噴 error
//(b)
int get();
double get(); // 只有 return type 不一樣會噴 error
//(c)
int *reset(int *);
double *reset(double *); // low level 的 type 不一樣，合法