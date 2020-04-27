#ifndef _BLOB_PTR_H_
#define _BLOB_PTR_H_

#include <src/Blob.h>
#include <memory> // std::weak_ptr
#include <vector> // std::vector
#include <string> // std::string
#include <exception> // std::out_of_range, std::runtime_error

template <typename T>
class BlobPtr;

template <typename T>
bool operator==(const BlobPtr<T>& Lhs, const BlobPtr<T>& Rhs) {
    if (Lhs.WPtr_.lock() != Rhs.WPtr_.lock()) {
        throw std::runtime_error("BlobPtrs point to different Blobs!");
    }
    return Lhs.Size_ == Rhs.Size_;
}

template <typename T>
bool operator!=(const BlobPtr<T>& Lhs, const BlobPtr<T>& Rhs) {
    return !(Lhs == Rhs);
}

template <typename T>
bool operator<(const BlobPtr<T>& Lhs, const BlobPtr<T>& Rhs) {
    if (Lhs.WPtr_.lock() != Rhs.WPtr_.lock()) {
        throw std::runtime_error("BlobPtrs point to different Blobs!");
    }
    return Lhs.Size_ < Rhs.Size_;
}

template <typename T>
class BlobPtr {
    friend bool operator==<T>(const BlobPtr<T>& LhS, const BlobPtr<T> &Rhs);
    friend bool operator!=<T>(const BlobPtr<T>& LhS, const BlobPtr<T> &Rhs);
    friend bool operator< <T>(const BlobPtr<T>& LhS, const BlobPtr<T> &Rhs);

public:
    BlobPtr() = default;
    BlobPtr(Blob<T> &B, std::size_t Size = 0) : WPtr_(B.Data_), Size_(Size) {}

    T& operator*() const {
        check_(Size_, "dereference out of range");
        return (*(WPtr_.lock()))[Size_];
    }

    BlobPtr& operator++() {
        check_(Size_, "increment out of range");
        ++Size_;
        return *this;
    }

    BlobPtr operator++(int) {
        auto Temp = *this;
        ++*this;
        return Temp;
    }

    BlobPtr& operator--() {
        check_(Size_, "decrement out of range");
        --Size_;
        return *this;
    }

    BlobPtr operator--(int) {
        auto Temp = *this;
        --*this;
        return Temp;
    }
private:
    std::shared_ptr<std::vector<T>> check_(std::size_t i, const std::string &Msg) const {
        auto p = WPtr_.lock();
        if (!p) {
            throw std::runtime_error("unbound weak pointer");
        }
        if (i >= p->size()) {
            throw std::out_of_range(Msg);
        }

        return p;
    }

    std::weak_ptr<std::vector<T>> WPtr_;
    std::size_t Size_ = 0;
};

#endif