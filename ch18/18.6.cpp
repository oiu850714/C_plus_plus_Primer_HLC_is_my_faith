//(a)
class exceptionType {};

//(c)
typedef int EXCPTYPE;

int main() {
  // (a)
  try {
    exceptionType *e = new exceptionType();
    throw e;
  } catch (exceptionType *pet) {
  }

  // (b)
  try {
    // you can throw whatever type, catch-all handler will catch it anyway
    throw 87;
  } catch (...) {
  }

  // (c)
  try {
    EXCPTYPE i = 9487;
    throw i;
  } catch (EXCPTYPE) {
  }
}