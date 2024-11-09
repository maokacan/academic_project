#ifndef CUS_LIST_H_
#define CUS_LIST_H_

#include <gtest/gtest.h>

#include <iostream>
#include <limits>
#include <stdexcept>

namespace custom {
template <typename T>
class ListIterator;

template <typename T>
class ListConstIterator;

template <typename T>
class list {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;
  using size_type = size_t;

  list() : head(nullptr), tail(nullptr), size_list(0) {}

  list(size_type n) : head(nullptr), tail(nullptr), size_list(0) {
    for (size_type i = 0; i < n; ++i) {
      push_back(value_type());
    }
  }

  list(std::initializer_list<value_type> const& items)
      : head(nullptr), tail(nullptr), size_list(0) {
    for (const auto& item : items) {
      push_back(item);
    }
  }

  list(const list& l) : list() {
    Node* current = l.head;
    while (current) {
      push_back(current->data);
      current = current->next;
    }
  }

  list& operator=(const list& l) {
    if (this != &l) {
      list copy(l);
      copy.swap(*this);
    }
    return *this;
  }

  list(list&& l) : head(l.head), tail(l.tail), size_list(l.size_list) {
    l.head = nullptr;
    l.tail = nullptr;
    l.size_list = 0;
  }

  list& operator=(list&& l) {
    if (this != &l) {
      clear();
      swap(l);
    }
    return *this;
  }

  ~list() { clear(); }

  reference front() {
    if (empty()) throw std::out_of_range("List is empty");
    return head->data;
  }

  const_reference front() const {
    if (empty()) throw std::out_of_range("List is empty");
    return head->data;
  }

  reference back() {
    if (empty()) throw std::out_of_range("List is empty");
    return tail->data;
  }

  const_reference back() const {
    if (empty()) throw std::out_of_range("List is empty");
    return tail->data;
  }

  iterator begin() { return iterator(head); }
  iterator end() { return iterator(nullptr); }
  const_iterator cbegin() const { return const_iterator(head); }
  const_iterator cend() const { return const_iterator(nullptr); }
  iterator last() { return iterator(tail); }
  const_iterator last() const { return const_iterator(tail); }

  bool empty() const { return size_list == 0; }
  size_type size() const { return size_list; }
  size_type max_size() const {
    return (std::numeric_limits<size_type>::max() / sizeof(Node));
  }

  void clear() {
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
      next = current->next;
      delete current;
      current = next;
    }
    head = nullptr;
    tail = nullptr;
    size_list = 0;
  }

  void swap(list& other) {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(size_list, other.size_list);
  }

  void push_back(const value_type& value) {
    Node* new_node = new Node(value);
    if (tail) {
      tail->next = new_node;
      new_node->prev = tail;
      tail = new_node;
    } else
      head = tail = new_node;
    size_list++;
  }

  void push_front(const_reference value) {
    Node* new_node = new Node(value);
    if (head) {
      new_node->next = head;
      head->prev = new_node;
      head = new_node;
    } else
      head = tail = new_node;
    size_list++;
  }

  void pop_front() {
    if (empty()) throw std::out_of_range("List is empty");

    Node* old_head = head;
    head = head->next;
    if (head)
      head->prev = nullptr;
    else
      tail = nullptr;
    delete old_head;
    size_list--;
  }

  void pop_back() {
    if (empty()) throw std::out_of_range("List is empty");
    Node* old_tail = tail;
    tail = tail->prev;
    if (tail)
      tail->next = nullptr;
    else
      head = nullptr;
    delete old_tail;
    size_list--;
  }

  void reverse() {
    if (empty() || head == tail) return;

    Node* current = head;
    Node* tmp = nullptr;

    while (current != nullptr) {
      tmp = current->prev;
      current->prev = current->next;
      current->next = tmp;
      current = current->prev;
    }

    tmp = head;
    head = tail;
    tail = tmp;
  }

  void erase(iterator pos) {
    if (pos == end()) {
      throw std::out_of_range("Iterator out of range");
    }

    Node* node_to_delete = pos.ptr;
    if (node_to_delete == head) {
      pop_front();
    } else if (node_to_delete == tail) {
      pop_back();
    } else {
      Node* prev_node = node_to_delete->prev;
      Node* next_node = node_to_delete->next;
      prev_node->next = next_node;
      next_node->prev = prev_node;
      delete node_to_delete;
      size_list--;
    }
  }

  iterator insert(iterator pos, const_reference value) {
    if (empty()) {
      push_back(value);
      return iterator(tail);
    } else if (pos == end()) {
      push_back(value);
      return iterator(tail);
    } else if (pos == begin()) {
      push_front(value);
      return iterator(head);
    } else {
      Node* new_node = new Node(value);
      Node* current = pos.ptr;
      Node* prev_node = current->prev;

      new_node->next = current;
      new_node->prev = prev_node;
      prev_node->next = new_node;
      current->prev = new_node;

      ++size_list;
      return iterator(new_node);
    }
  }

  void merge(list& other) {
    iterator this_it = begin();
    iterator other_it = other.begin();
    while (other_it != other.end()) {
      if (this_it != end() && *this_it <= *other_it)
        ++this_it;
      else {
        iterator next_other_it = other_it;
        ++next_other_it;
        insert(this_it, *other_it);
        other.erase(other_it);
        other_it = next_other_it;
      }
    }
  }

  void splice(const_iterator pos, list& other) {
    for (iterator it = other.begin(); it != other.end(); ++it) insert(pos, *it);
    other.clear();
  }

  void unique() {
    if (empty()) return;
    for (auto it = ++(begin()); it != end() && !empty(); ++it) {
      if (it.ptr->data == it.ptr->prev->data) {
        iterator to_delete = iterator(it.ptr->prev);
        erase(to_delete);
      }
    }
  }

  void sort() {
    if (empty()) return;
    for (auto current = ++begin(); current != end() && !empty(); ++current) {
      if (current.ptr->data < current.ptr->prev->data) {
        std::swap(current.ptr->data, current.ptr->prev->data);
        sort();
      }
    }
  }

  template <typename... Args>
  void insert_many_back(Args&&... args) {
    (push_back(std::forward<Args>(args)), ...);
  }

  template <typename... Args>
  void insert_many_front(Args&&... args) {
    (push_front(std::forward<Args>(args)), ...);
  }

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args&&... args) {
    auto iter = pos;
    if (iter == end()) {
      (insert(end(), value_type(std::forward<Args>(args))), ...);
      return begin();
    }
    if constexpr (sizeof...(args) > 0) {
      auto original_pos = iter;
      (insert(iter, value_type(std::forward<Args>(args))), ...);
      iter = original_pos;
      for (size_type i = 0; i < sizeof...(args); ++i) {
        --iter;
      }
    }
    return iter;
  }

 private:
  struct Node {
    value_type data;
    Node* next;
    Node* prev;

    Node(const value_type& value) : data(value), next(nullptr), prev(nullptr) {}
  };
  Node* head;
  Node* tail;
  size_type size_list;

  friend class ListIterator<T>;
  friend class ListConstIterator<T>;
};

template <typename T>
class ListIterator {
 public:
  using reference = T&;
  using const_reference = const T&;
  using value_type = T;

  ListIterator() : ptr(nullptr) {}

  ListIterator(typename list<T>::Node* node_ptr) : ptr(node_ptr) {}

  reference operator*() {
    if (!ptr) throw std::invalid_argument("It's empty iterator!");
    return ptr->data;
  }

  const_reference operator*() const {
    if (!ptr) throw std::invalid_argument("It's empty iterator!");
    return ptr->data;
  }

  ListIterator& operator++() {
    if (ptr) ptr = ptr->next;
    return *this;
  }

  ListIterator& operator--() {
    if (ptr) ptr = ptr->prev;
    return *this;
  }

  ListIterator operator++(int) {
    ListIterator it(*this);
    if (ptr) ptr = ptr->next;
    return it;
  }

  ListIterator operator--(int) {
    ListIterator it(*this);
    if (ptr) ptr = ptr->prev;
    return it;
  }

  bool operator==(const ListIterator& other) const {
    return this->ptr == other.ptr;
  }

  bool operator!=(const ListIterator& other) const {
    return this->ptr != other.ptr;
  }

 private:
  typename list<T>::Node* ptr;
  friend list<T>;
};

template <typename T>
class ListConstIterator : public ListIterator<T> {
 public:
  using reference = const T&;
  using value_type = T;

  ListConstIterator(typename list<T>::Node* node_ptr)
      : ListIterator<T>(node_ptr) {}
  ListConstIterator(const ListIterator<T>& other) : ListIterator<T>(other) {}
  reference operator*() const { return ListIterator<T>::operator*(); }
};
}  // namespace custom

#endif  // CUS_LIST_H_
