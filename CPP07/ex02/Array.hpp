#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class Array {
 private:
  T* elements_;
  size_t size_;

 public:
  Array() : elements_(NULL), size_(0) {}

  // サイズを指定するコンストラクタ
  Array(unsigned int n) : elements_(new T[n]()), size_(n) {}

  Array(const Array& other) : elements_(NULL), size_(0) {
    *this = other;
  }

  ~Array() {
    delete[] elements_;
  }

  Array& operator=(const Array& other) {
    if (this != &other) {
      delete[] elements_;
      size_ = other.size_;
      elements_ = new T[size_];
      for (size_t i = 0; i < size_; i++) {
        elements_[i] = other.elements_[i];
      }
    }
    return *this;
  }

  // 添字演算子
  T& operator[](size_t index) {
    if (index >= size_) {
      throw std::exception();
    }
    return elements_[index];
  }

  // 添字演算子（const版）
  const T& operator[](size_t index) const {
    if (index >= size_) {
      throw std::exception();
    }
    return elements_[index];
  }

  size_t size() const {
    return size_;
  }
};

#endif
