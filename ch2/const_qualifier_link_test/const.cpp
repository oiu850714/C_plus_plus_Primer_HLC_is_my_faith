#include "const.h"
extern const int c = 100;
// "extern" and declarator let this const can be accessed to other files that
// include const.h

// reference:
// https://stackoverflow.com/questions/14894698/why-does-extern-const-int-n-not-work-as-expected
// https://stackoverflow.com/questions/1358400/what-is-external-linkage-and-internal-linkag