// Exercise 7.31: Define a pair of classes X and Y, in which X has a pointer to
// Y,and Y has an object of type X.

class X;
class Y;

class X {
  Y *y_ptr = nullptr;
};

class Y {
  X x;
};

// You can move the definition of Y before definition of X, it will be error