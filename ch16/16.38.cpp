// because make_shared<T>'s function arguments are used to pass to T's ctor,
// compiler cannot deduce T simply by these arguments
// or you can refer to cplusplus.com/cppreference.com:
template <class T, class... Args> shared_ptr<T> make_shared(Args &&... args);
// although now we don't know WTF &&... is, but we can see that T is used in the
// return type of make_shared<T>, so compiler cannot deduced T by function
// arguments