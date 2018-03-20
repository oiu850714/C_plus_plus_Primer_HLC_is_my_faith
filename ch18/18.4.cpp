// Exercise 18.4: Looking ahead to the inheritance hierarchy in Figure 18.1 (p.
// 783), explain what’s wrong with the following try block. Correct it.
#include <stdexcept>
using std::exception;
using std::runtime_error;
using std::overflow_error;

int main() {
  try {
    // use ofthe C++ standard library
  } catch (exception) {
    // ...
  } catch (const runtime_error &re) {
    // ...
  } catch (overflow_error eobj) {
    /* ... */
  }

  // hierarchy: execption <- runtime_error <- overflow_error
  try {
    // use ofthe C++ standard library
  } catch (overflow_error eobj) {
    /* ... */
  } catch (const runtime_error &re) {
    // ...
  } catch (exception) {
    // ...
  }
}