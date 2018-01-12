int main() { int null = 0, *p = null; }
// illegal lol, p cannot use int's value to initialize
// It can be modified like this:
//      int *p = nullptr;