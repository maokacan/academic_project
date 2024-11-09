#ifndef CUS_STACK_H_
#define CUS_STACK_H_

#include "custom_list.h"

namespace custom {
template <typename T, typename Container = list<T>>
class stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  stack() : container_stack() {}
  stack(std::initializer_list<value_type> const &items)
      : container_stack(items) {}
  stack(const stack &s) : container_stack(s.container_stack) {}
  stack(stack &&s) noexcept : container_stack(std::move(s.container_stack)) {}
  ~stack() {}

  stack &operator=(const stack &s) {
    if (this != &s) container_stack = s.container_stack;
    return *this;
  }

  stack &operator=(stack &&s) noexcept {
    if (this != &s) container_stack = std::move(s.container_stack);
    return *this;
  }

  reference top() {
    if (!empty()) {
      return container_stack.back();
    }
    throw std::out_of_range("Stack is empty");
  }

  const_reference top() const {
    if (!empty()) {
      return container_stack.back();
    }
    throw std::out_of_range("Stack is empty");
  }

  bool empty() const { return container_stack.empty(); }
  size_type size() const { return container_stack.size(); }
  void push(const_reference value) { container_stack.push_back(value); }

  void pop() {
    if (!empty()) container_stack.pop_back();
  }

  void swap(stack &other) noexcept {
    container_stack.swap(other.container_stack);
  }

  template <typename... Args>
  void insert_many_back(Args &&...args) {
    (container_stack.push_back(std::forward<Args>(args)), ...);
  }

 private:
  Container container_stack;
};
}  // namespace custom

#endif  // CUS_STACK_H_