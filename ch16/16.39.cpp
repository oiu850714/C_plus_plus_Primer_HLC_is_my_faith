template <typename T> int compare(const T &v1, const T &v2) {
  if (v1 < v2)
    return -1;
  if (v2 < v1)
    return 1;
  return 0;
}

#include <string>

int main() {
  compare<std::string>("len5", "len--7");
  // note: never pass const char*, it will compare two pointers, which is UB:
  // compare<const char*>("len5", "len--7");
}