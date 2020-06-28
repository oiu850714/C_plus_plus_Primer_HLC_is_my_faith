class A {};
class B : public A {};
class C : public B {};
class X {};
class Y {};
class Z : public X, public Y {};
class MI : public C, public Z {};

// (((A) B) C), ((X), (Y), Z), MI
// order: A, B, C, X, Y, Z
// The number of parentheses means the level of hierarchy above MI