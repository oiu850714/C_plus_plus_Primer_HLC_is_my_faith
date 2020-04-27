#ifndef _BLOB_H_
#define _BLOB_H_

#include <vector>
#include <memory>
#include <string>
#include <exception>

template <typename T>
class BlobPtr;

template <typename T>
class Blob {
    friend class BlobPtr<T>;
public:
    using value_type = T;
    using size_type = typename std::vector<T>::size_type;

    Blob();
    Blob(const Blob& other);
    Blob(std::initializer_list<T> il);

    template <typename InputIt>
    Blob(InputIt Begin, InputIt End);

    size_type size() const { return Data_->size(); }
    bool empty() const { return Data_->empty(); }
    void push_back(const T &Element) { return Data_->push_back(Element); }
    void push_back(T &&Element) { return Data_->push_back(std::move(Element)); }
    void pop_back() { Data_->pop_back(); }

    BlobPtr<T> begin() { return BlobPtr<T>(*this); }
    BlobPtr<T> end() { return BlobPtr<T>(*this, Data_->size()); }

    T& back() {check_(0, "access empty Blob"); return Data_->back(); }
    const T& back() const {check_(0, "access empty Blob"); return Data_->back(); }
    T& front() {check_(0, "access empty Blob"); return Data_->front(); }
    const T& front() const {check_(0, "access empty Blob"); return Data_->front(); }
    T& operator[](size_type i) {check_(i, "invalid index"); return (*Data_)[i]; }
    const T& operator[](size_type i) const {check_(i, "invalid index"); return (*Data_)[i]; }

private:
    std::shared_ptr<std::vector<T>> Data_;

    void check_(size_type i, const std::string&) const;
};

template <typename T>
Blob<T>::Blob() : Data_(std::make_shared<std::vector<T>>()) {

}

template <typename T>
Blob<T>::Blob(const Blob<T>& Other) : Data_(Other.Data_) {

}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : Data_(std::make_shared<std::vector<T>>(il)) {

}

template <typename T>
template <typename InputIt>
Blob<T>::Blob(InputIt Begin, InputIt End) : Data_(std::make_shared<std::vector<T>>(Begin, End)) {

}

template <typename T>
void Blob<T>::check_(size_type i, const std::string &Msg) const {
    if (i >= Data_->size()) {
        throw std::out_of_range(Msg);
    }
}
#endif