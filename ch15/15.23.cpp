// remove parameter int, or defined another fcn that has no arguments
class Base {
public:
  virtual int fcn();
};
class D1 : public Base {
public:
  // hides fcn in the Base; this fcn is not virtual
  // D1 inherits the definition of Base::fcn()

  // ex 15.23
  virtual int fcn() override; // parameter list differs from fcnin Base
  virtual void f2(); // new virtual function that does not exist in Base
};
class D2 : public D1 {
public:
  int fcn(int); // nonvirtual function hides D1::fcn(int)
  int fcn();    // overrides virtual fcn from Base
  void f2();    // overrides virtual f2 from D1
};

int main() {
  Base bobj;
  D1 d1obj;
  D2 d2obj;
  Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;

  bp1->fcn(); // virtual call, will call Base::fcn at run time

  // ex 15.23
  bp2->fcn(); // virtual call, will call D1::fcn at run time

  bp3->fcn(); // virtual call, will call D2::fcn at run time

  // remaining code doesn't call fcn, omit
}