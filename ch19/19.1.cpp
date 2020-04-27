#include <new>
#include <cstdlib>

void *operator new(size_t size) {
    if (void *mem = malloc(size)) {
        return mem;
    } else {
        throw std::bad_alloc();
    }
}

void operator delete(void *p) noexcept {
    free(p);
}

int main() {
    return 0;
}