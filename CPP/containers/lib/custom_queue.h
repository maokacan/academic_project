#ifndef CUS_QUEUE_H_
#define CUS_QUEUE_H_

#include "custom_list.h"

namespace custom {
template <typename T, typename Container = list<T>>
class queue {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  queue() : container_queue() {}
  queue(std::initializer_list<value_type> const &items)
      : container_queue(items) {}
  queue(const queue &q) : container_queue(q.container_queue) {}
  queue(queue &&q) noexcept : container_queue(std::move(q.container_queue)) {}
  ~queue() {}

  queue &operator=(const queue &q) {
    if (this != &q) container_queue = q.container_queue;
    return *this;
  }

  queue &operator=(queue &&q) noexcept {
    if (this != &q) container_queue = std::move(q.container_queue);
    return *this;
  }

  const_reference front() const { return container_queue.front(); }
  reference front() { return container_queue.front(); }

  const_reference back() const { return container_queue.back(); }
  reference back() { return container_queue.back(); }

  bool empty() const { return container_queue.empty(); }
  size_type size() const { return container_queue.size(); }

  void push(const_reference value) { container_queue.push_back(value); }

  void pop() {
    if (!empty()) container_queue.pop_front();
  }

  void swap(queue &other) noexcept {
    container_queue.swap(other.container_queue);
  }

  template <typename... Args>
  void insert_many_back(Args &&...args) {
    (container_queue.push_back(std::forward<Args>(args)), ...);
  }

 private:
  Container container_queue;
};
}  // namespace custom

#endif  // CUS_QUEUE_H_