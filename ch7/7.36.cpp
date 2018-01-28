struct X {
  // X(int i, int j) : base(i), rem(base % j) {}
  X(int i, int j) : base(i), rem(i % j) {}
  // member base is uninitialized when used in base % j
  // use i in rem's initializer directly to prevent from concerning the order
  // members are declared in class
  int rem, base;
};