#include <sstream>
#include <iostream>

template <typename InputIt, typename T>
InputIt selfFind(InputIt beg, InputIt end, const T &val) {
    while (beg != end) {
        if (*beg == val) {
            return beg;
        }
        beg++;
    }

    return end;
}

template <typename ARR>
void print(std::ostream& Os, const ARR &arr) {
    for (const auto &e : arr) {
        Os << e << " ";
    }
    Os << std::endl;
}

template <typename T, unsigned int SIZE>
T* selfBeg(T (&arr) [SIZE]) {
    return arr;
}

template <typename T, unsigned int SIZE>
T* selfEnd(T (&arr) [SIZE]) {
    return arr + SIZE;
}

template <typename T, unsigned int SIZE>
unsigned int arrSize(T (&arr) [SIZE]) {
    return SIZE;
}

template <typename T>
class demo {
public:
    demo<T>() { std::cout << "XDD" << std::endl; }

    demo<T>& ret();
};

/*
template <typename T>
demo<T>::demo() { std::cout << "XDD" << std::endl; }
*/

template <typename T>
demo<T>& demo<T>::ret() { return *this; }

template <typename Foo>
void foo(const Foo&);

template <typename LOL>
class lol {
    friend void foo<LOL>(const LOL&);
public:
    lol(LOL l) { foo(l); }
};

template <typename Foo>
void foo(const Foo&) {
    
}


template <typename C>
void printContainer(std::ostream& Os, const C &c) {
    for (typename C::size_type Size = 0; Size < c.size(); ++Size) {
        Os << c[Size] << " ";
    }
    Os << std::endl;
}

template <typename C>
void printContainer2(std::ostream& Os, const C &c) {
    for (auto It = c.begin(); It != c.end(); ++It) {
        Os << *It << " ";
    }
    Os << std::endl;
}

template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2) {
    f(t2, t1);
}

template <typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2) {
    f(t2, t1);
}

template <typename F, typename T1, typename T2>
void flip3(F f, T1 &&t1, T2 &&t2) {
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f(int i, int &j) {
    std::cout << i << " " << ++j << std::endl;
}


void g(int &&i, int &j) {
    std::cout << i << " " << ++j << std::endl;
}

template <typename T>
std::string debug_rep(const T &t) {
    std::stringstream ss;
    ss << t;
    return ss.str();
}

template <typename T>
std::string debug_rep(T *t) {
    std::stringstream ss;
    ss << "address: " << t;
    if (t != nullptr) {
        ss << ", value: " << *t;
    } else {
        ss << ", nullptr";
    }
    return ss.str();
}

std::string debug_rep(const std::string &str) {
    return '"' + str + '"';
}

std::string debug_rep(const char *c_str) {
    return debug_rep(std::string(c_str));
}

std::string debug_rep(char *c_str) {
    return debug_rep(std::string(c_str));
}

template <typename T>
void debug_print(std::ostream& Os, T t);


template <typename T, typename... Args>
void debug_print(std::ostream& Os, T t, Args... rest) {
    Os << t << ", ";
    debug_print(Os, debug_rep(rest)...);
}


template <typename T>
void debug_print(std::ostream& Os, T t) {
    Os << debug_rep(t);
}


template <typename... T>
void justSuck(std::ostream& Os, std::vector<T>... t) {
}