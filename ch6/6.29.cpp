// SEE: https://github.com/Mooophy/Cpp-Primer/tree/master/ch06#exercise-629
// Depends on the type of elements of initializer_list. When the type is
// PODType(google it), reference is unnecessary. Because POD is cheap to
// copy(such as int). Otherwise, Using reference(const) is the better choice.