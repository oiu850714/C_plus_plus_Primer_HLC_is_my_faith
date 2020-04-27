#ifndef _VEC_H_
#define _VEC_H_
#include <string>
#include <memory> // allocator
#include <utility>
#include <tuple> // std::tie
#include <algorithm>

template <typename T>
class Vec {
public:
    // ctor
    Vec();
    Vec(const Vec&);
    Vec(Vec&&);
    Vec(std::initializer_list<T>);
    Vec& operator=(const Vec&);
    Vec& operator=(Vec&&);

    size_t size() const { return FirstFree_ - Elements_; }
    size_t capacity() const { return Cap_ - Elements_; }
    void reserve(size_t);
    T* begin() { return Elements_; }
    const T* begin() const { return Elements_; }
    T* end() { return FirstFree_; }
    const T* end() const { return FirstFree_; }
    void push_back(const T&);
    void push_back(T&&);

    template <typename... Args>
    void emplace_back(Args&&... args);


private:
    static std::allocator<T> Alloc_;

    T *Elements_;
    T *FirstFree_;
    T *Cap_;

    void checkSizeOrRealloc_() { if (size() == capacity()) reallocate_(); }
    void reallocate_();
    std::pair<T*, T*> allocNCopy_(const T*, const T*);
    void free_();
    void rangeInitialize_(const T*, const T*);
};

template <typename T>
std::allocator<T> Vec<T>::Alloc_;

template <typename T>
Vec<T>::Vec() : Elements_(nullptr), FirstFree_(nullptr), Cap_(nullptr) {
}

template <typename T>
Vec<T>::Vec(const Vec& other) {
    rangeInitialize_(other.begin(), other.end());
}

template <typename T>
Vec<T>::Vec(std::initializer_list<T> il) {
    rangeInitialize_(il.begin(), il.end());
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec& rhs) {
    auto NewRange = allocNCopy_(rhs.begin(), rhs.end());

    free_();

    Elements_ = NewRange.first;
    FirstFree_ = Cap_ = NewRange.second;

    return *this;
}

template <typename T>
void Vec<T>::push_back(const T &str) {
    checkSizeOrRealloc_();

    Alloc_.construct(FirstFree_++, str);
}

template <typename T>
void Vec<T>::push_back(T &&str) {
    checkSizeOrRealloc_();

    Alloc_.construct(FirstFree_++, std::move(str));
}

template <typename T>
void Vec<T>::reserve(size_t NewSize) {
    if (NewSize >= size() * 2) {
        reallocate_();
    }
}

template <typename T>
std::pair<T*, T*> Vec<T>::allocNCopy_(const T *begin, const T *end) {
    auto NewBlock = Alloc_.allocate(end - begin);
    return {NewBlock, std::uninitialized_copy(begin, end, NewBlock)};
}

template <typename T>
void Vec<T>::free_() {
    if (!Elements_) {
        return;
    }

    std::for_each(Elements_, FirstFree_, [&Alloc_ = Alloc_] (auto str) { Alloc_.destroy(&str); });
    Alloc_.deallocate(Elements_, Cap_ - Elements_);
}

template <typename T>
void Vec<T>::reallocate_() {
    auto NewAllocSize = size() ? 2 * size() : 1;
    auto NewAllocBlock = Alloc_.allocate(NewAllocSize);

    auto BlockIt = NewAllocBlock, OldIT = Elements_;
    while (OldIT != FirstFree_) {
        Alloc_.construct(BlockIt++, std::move(*OldIT++));
    }

    free_();
    Elements_ = NewAllocBlock;
    FirstFree_ = BlockIt;
    Cap_ = Elements_ + NewAllocSize;
}

template <typename T>
void Vec<T>::rangeInitialize_(const T *begin, const T *end) {
    std::tie(Elements_, FirstFree_) = allocNCopy_(begin, end);
    Cap_ = FirstFree_;
}

template <typename T>
template <typename... Args>
void Vec<T>::emplace_back(Args&&... args) {
    checkSizeOrRealloc_();
    Alloc_.construct(FirstFree_++, std::forward<Args>(args)...);
}

#endif
