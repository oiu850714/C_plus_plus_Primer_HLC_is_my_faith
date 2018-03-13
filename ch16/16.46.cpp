int main() {
  for (size_t i = 0; i != size(); ++i)
    alloc.construct(dest++, std::move(*elem++));
  // *elem++ returns lvalue, std::move converts it to rvalue, which passed to
  // allocator<string>::construct
  // SEE: http://www.cplusplus.com/reference/memory/allocator/construct/
  // passed to move version
}