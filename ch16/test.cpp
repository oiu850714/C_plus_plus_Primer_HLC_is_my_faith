#include <vector>
#include <iostream>
#include <memory>
#include <algorithm>
#include <string>

#include <src/Vec.h>
#include <src/Blob.h>

#include <src/BlobPtr.h>
#include <src/some_utils.h>

void *operator new(size_t size) {
    if (void *mem = malloc(size)) {
        std::cout << "new success" << std::endl;
        return mem;
    } else {
        throw std::bad_alloc();
    }
}

void operator delete(void *p) noexcept {
    std::cout << "delete success" << std::endl;
    free(p);
}

int main() {
    Vec<int> V1{1, 2, 3, 4, 5};
}
