// SEE Primer p.679
// 1. const conversions: A function parameter that is a reference (or pointer)
// to a const can be passed a reference (or pointer) to a nonconst object (§
// 4.11.2, p. 162).

// 2. Array- or function-to-pointer conversions: If the function parameter is
// not a reference type, then the normal pointer conversion will be applied to
// arguments of array or function type. An array argument will be converted to a
// pointer to its first element. Similarly, a function argument will be
// converted to a pointer to the function’s type (§ 4.11.2, p. 161).