#ifndef CUS_VECTOR_H_
#define CUS_VECTOR_H_

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <utility>

namespace custom {
template <typename T>
class vector {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = size_t;

  vector() : data_(nullptr), size_(0), capacity_(0) {}

  explicit vector(size_type n)
      : data_(new value_type[n]), size_(n), capacity_(n) {
    std::fill(data_, data_ + size_, value_type());
  }

  vector(std::initializer_list<value_type> const& items)
      : data_(new value_type[items.size()]),
        size_(items.size()),
        capacity_(items.size()) {
    std::copy(items.begin(), items.end(), data_);
  }

  vector(const vector& v)
      : data_(new value_type[v.capacity_]),
        size_(v.size_),
        capacity_(v.capacity_) {
    std::copy(v.data_, v.data_ + v.size_, data_);
  }

  vector(vector&& v) noexcept
      : data_(v.data_), size_(v.size_), capacity_(v.capacity_) {
    v.data_ = nullptr;
    v.size_ = 0;
    v.capacity_ = 0;
  }

  ~vector() { delete[] data_; }

  vector& operator=(vector&& v) noexcept {
    if (this != &v) {
      delete[] data_;
      data_ = v.data_;
      size_ = v.size_;
      capacity_ = v.capacity_;
      v.data_ = nullptr;
      v.size_ = 0;
      v.capacity_ = 0;
    }
    return *this;
  }

  reference at(size_type pos) {
    if (pos >= size_) {
      throw std::out_of_range(
          "vector::at: pos (which is " + std::to_string(pos) +
          ") >= this->size() (which is " + std::to_string(size_) + ")");
    }
    return data_[pos];
  }

  const_reference at(size_type pos) const {
    if (pos >= size_) {
      throw std::out_of_range(
          "vector::at: pos (which is " + std::to_string(pos) +
          ") >= this->size() (which is " + std::to_string(size_) + ")");
    }
    return data_[pos];
  }

  reference operator[](size_type pos) { return data_[pos]; }

  const_reference operator[](size_type pos) const { return data_[pos]; }

  reference front() {
    if (size_ == 0) {
      throw std::out_of_range("vector::front: vector is empty");
    }
    return *begin();
  }

  const_reference front() const {
    if (size_ == 0) {
      throw std::out_of_range("vector::front: vector is empty");
    }
    return *begin();
  }

  reference back() {
    if (size_ == 0) {
      throw std::out_of_range("vector::back: vector is empty");
    }
    return *(end() - 1);
  }

  const_reference back() const {
    if (size_ == 0) {
      throw std::out_of_range("vector::back: vector is empty");
    }
    return *(end() - 1);
  }

  T* data() noexcept { return data_; }

  const T* data() const noexcept { return data_; }

  iterator begin() noexcept { return data_; }

  const_iterator begin() const noexcept { return data_; }

  iterator end() noexcept { return data_ + size_; }

  const_iterator end() const noexcept { return data_ + size_; }

  size_type size() const noexcept { return size_; }

  bool empty() const noexcept { return size_ == 0; }

  size_type max_size() const noexcept {
    return std::numeric_limits<size_type>::max() / sizeof(value_type);
  }

  size_type capacity() const noexcept { return capacity_; }

  void shrink_to_fit() {
    if (capacity_ > size_) {
      reserve(size_);
    }
  }

  void clear() noexcept { size_ = 0; }

  void reserve(size_type new_capacity) {
    if (new_capacity > capacity_) {
      value_type* new_data = new value_type[new_capacity];
      if (data_) {
        std::move(data_, data_ + size_, new_data);
        delete[] data_;
      }
      data_ = new_data;
      capacity_ = new_capacity;
    }
  }

  iterator insert(iterator pos, const_reference value) {
    size_type index = pos - begin();
    if (size_ == capacity_) {
      reserve(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    std::move_backward(begin() + index, end(), end() + 1);
    data_[index] = value;
    ++size_;
    return begin() + index;
  }

  void erase(iterator pos) {
    if (pos < begin() || pos >= end()) {
      throw std::out_of_range("vector::erase: pos is out of range");
    }
    size_type index = pos - begin();
    std::move(begin() + index + 1, end(), begin() + index);
    --size_;
  }

  void push_back(const_reference value) {
    if (size_ == capacity_) {
      reserve(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    data_[size_] = value;
    ++size_;
  }

  void pop_back() {
    if (size_ > 0) {
      --size_;
    }
  }

  void swap(vector& other) noexcept {
    std::swap(data_, other.data_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
  }

  template <typename... Args>
  void insert_many_back(Args&&... args) {
    (push_back(std::forward<Args>(args)), ...);
  }

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args&&... args) {
    auto iter = pos;
    if (iter == end()) {
      (push_back(std::forward<Args>(args)), ...);
      return end() - sizeof...(args);
    } else {
      size_type index = iter - begin();
      (insert(begin() + index++, std::forward<Args>(args)), ...);
      return begin() + index - 1;
    }
  }

 private:
  value_type* data_;
  size_type size_;
  size_type capacity_;
};
}  // namespace custom

#endif  // CUS_VECTOR_H_