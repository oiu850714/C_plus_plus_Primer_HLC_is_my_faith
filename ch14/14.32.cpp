#include "14.30/StrBlob.h"

class Ptr_to_StrBlobPtr {
public:
  StrBlobPtr *operator->() { return ptr; }
  StrBlobPtr operator*() { return *ptr; }

private:
  StrBlobPtr *ptr = nullptr;
};