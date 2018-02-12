// 1.
// 一種 copy control，當你把某 class 的 object 做 assign 時會使用到:
// class class_name {
// public:
//   class_name &operator=(const class_name &);
// };
// class_name obj1, obj2;
// obj1 = obj2; // use copy-assignment operator

// 2.
// 如果合成的 copy-assignment operator 可以做 assign，那他會將 rhs of operator=
// 的所有 nonstatic members 都 call member 定義的 operator=，assign 給 lhs of
// operator= 的所有 nonstatic members

// 3.
// 當我們沒有定義 copy-assignment operator 時 compiler 就會幫我們合成一個