class Base { // OK
  //...
};
//(a)
class Derived : public Derived { // class cannot inherit itselt
  //...
};
//(b)
class Derived : private Base { // OK
  //...
};
//(c)
class Derived
    : public Base; // class declaration cannot include class derivation list