void print(int arr[], size_t size) {}

void print(int *begin, int *end) {}

// just implement these two version, other versions in textbook is to limited:
// 1. reference to array version can only receive array with same size
// 2. marker version is useless if we cannot specify which value in the array
// element type can be a marker