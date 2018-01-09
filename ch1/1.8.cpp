#include <iostream>
int main() {
  std::cout << "/*"; // legal
  std::cout << "*/"; // legal
  std::cout << /* "*/ " */; // illegal";
  std::cout << /* "*/ " /* " /*" */; // legal
}