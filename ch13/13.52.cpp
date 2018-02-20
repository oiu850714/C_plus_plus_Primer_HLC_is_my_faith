// https://github.com/Mooophy/Cpp-Primer/tree/master/ch13#exercise-1352
// and SEE Primer page 540, the parameter of operator= is nonreference type, and
// it will be copy initialized

hp = hp2;            // rhs will use copy constructor to initialize rhs
hp = std::move(hp2); // rhs will use move constructor to initialize rhs
