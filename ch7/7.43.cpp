class NoDefault {
public:
  NoDefault(int i) {}
};

class C {
public:
  C() : n(87) {}

private:
  NoDefault n;
};

int main() { C c; }