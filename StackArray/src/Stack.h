#pragma once
#include <memory>

template<class t_Data>
class Stack {
  t_Data *stack = nullptr;
  int numberOfItems = 0;
  int capacity = 0;

public:
  Stack() {
    stack = new t_Data[1];
    capacity = 1;
  }

  // To delete the array in the end
  ~Stack() {
    delete[] stack;
  }

  void push(const t_Data &item) {
    // To resize the array (time complexity O(n))
    if (numberOfItems == capacity) resize(2 * capacity);
    // Insert the given item into the array
    stack[numberOfItems++] = item;
  }

  t_Data pop() {
    if (isEmpty()) throw std::out_of_range("Stack is empty.");
    // The item we want to pop
    t_Data itemToPop = stack[--numberOfItems];
    // If too many items have been popped, resize the array (O(n))
    if (numberOfItems > 0 && numberOfItems == capacity/4) resize(capacity/2);
    return itemToPop;
  }

  // O(1)
  bool isEmpty() const {
    return numberOfItems == 0;
  }

  // O(1)
  int size() const {
    return numberOfItems;
  }

  // Create new array and copy everything to new array
  void resize(int _capacity) {
    t_Data *stackCopy = new t_Data[_capacity];

    for (int i = 0; i < numberOfItems; i++) {
      stackCopy[i] = stack[i];
    }

    delete[] stack;
    stack = stackCopy;
    capacity = _capacity;
  }
};