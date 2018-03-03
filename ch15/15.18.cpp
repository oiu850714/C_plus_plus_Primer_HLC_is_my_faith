// C++ Primer P.613: Member functions and friends of D can use the conversion to
// B regardless of how D inherits from B. The derived-to-base conversion to a
// direct base class is always accessible to members and friends of a derived
// class. -> this case applies on Pub_Derv, Priv_Derv, and Prot_Derv

// C++ Primer P.614: Member functions and friends of classes derived from D may
// use the derivedto-base conversion if D inherits from B using either public or
// protected. Such code may not use the conversion if D inherits privately from
// B. -> this case applies on Derived_from_Publc, Derived_from_Private, and
// Derived_from_Protected

class Base {
public:
  void memfcn(Base &b) { b = *this; } // legal
  void pub_mem();                     // public member
protected:
  int prot_mem; // protected member
private:
  char priv_mem; // private member
};
struct Pub_Derv : public Base {
public:
  void memfcn(Base &b) { b = *this; } // legal
  int f() { return prot_mem; }
};
struct Priv_Derv : private Base {
public:
  void memfcn(Base &b) { b = *this; } // legal
  int f1() const { return prot_mem; }
};

struct Prot_Derv : protected Base {
public:
  void memfcn(Base &b) { b = *this; } // legal
};

struct Derived_from_Public : public Pub_Derv {
public:
  void memfcn(Base &b) { b = *this; } // legal
  int use_base() { return prot_mem; }
};
struct Derived_from_Private : public Priv_Derv {
public:
  void memfcn(Base &b) { b = *this; } // illegal
};

struct Derived_from_Protected : public Prot_Derv {
public:
  void memfcn(Base &b) { b = *this; } // legal
};

int main() {
  // ex 15.18
  Pub_Derv d1;
  Priv_Derv d2;
  Prot_Derv d3;
  Derived_from_Public dd1;
  Derived_from_Private dd2;
  Derived_from_Protected dd3;

  Base *p = &d1; // d1 has type Pub_Derv
                 // legal

  p = &d2; // d2 has type Priv_Derv
           // illegal

  p = &d3; // d3 has type Prot_Derv
           // illegal

  p = &dd1; // dd1 has type Derived_from_Public
            // legal, from Derived_from_Public* to Pub_Derv*, and then from
            // Pub_Derv* to Base*

  p = &dd2; // dd2 has type Derived_from_Private
            // illegal

  p = &dd3; // dd3 has type Derived_from_Protected
            // illegal

  // C++ Primer P.613: User code may use the derived-to-base conversion only if
  // D inherits publicly from B. User code may not use the conversion if D
  // inherits from B using either protected or private.
}