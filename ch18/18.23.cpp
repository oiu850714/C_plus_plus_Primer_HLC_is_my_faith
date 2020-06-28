class A {};
class B : public A {};
class C : public B {};
class X {};
class Y {};
class Z : public X, public Y {};
class MI : public C, public Z {};

// 18.23
class D : public X, public C {};

int main() {
    D *pd = new D;

    // (a) valid
    X *px = pd;

    // (b) valid
    A *pa = pd;

    // (c) valid
    B *pb = pd;

    // (d) valid
    C *pc = pd;
}