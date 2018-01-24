class BigInt;
//(a)
inline bool eq(const BigInt &, const BigInt &) { return true; };
//(b)
void putValues(int *arr, int size);

// Both should be in header,
// non inline function should put their declaration in header
// inline function should put their definition in header