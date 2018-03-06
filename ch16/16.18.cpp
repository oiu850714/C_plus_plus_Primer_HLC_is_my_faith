//(a)
template <typename T, typename U, typename V> void f1(T, U, V);
//                    ^ need declared with keyword typename or class

//(b)
template <typename T> T f2(int &i);
//                              ^ cannot reuse templare parameter

//(c)
/*inline*/ template <typename T> inline T foo(T, unsigned int *);
//^ inline must declared after <>

//(d)
template <typename T> void f4(T, T);
//                    ^ need return type

//(e)
typedef char Ctype;
template <typename Ctype> Ctype f5(Ctype a);
// legal, but template parameter Ctype hides typedef's