#pragma once
#include <memory>
using std::unique_ptr;
using std::make_unique;

template<class t_Data>
class Stack {
  struct Node {
    t_Data data;
    unique_ptr<Node> nextNode;
    Node (const t_Data &_data): data(_data){}
  };
  
  unique_ptr<Node> head;
  int count = 0;

public:
  // Pushing is O(1);
  void push(const t_Data &newData) {
    if (!head) {
      head = make_unique<Node>(newData);
    } else {
      unique_ptr<Node> oldhead = std::move(head);
      head = make_unique<Node>(newData);
      head -> nextNode = std::move(oldhead);
    }
    ++count;
  }

  // O(1) as well
  t_Data pop() {
    if (isEmpty()) throw std::out_of_range("Stack is empty.");

    t_Data itemToPop = head -> data;
    unique_ptr<Node> temp = std::move(head -> nextNode);
    head = std::move(temp);
    --count;
    return itemToPop;
  }
  
  // O(1)
  bool isEmpty() const {
    return !head;
  }
  
  // O(1)
  int size() const {
    return count;
  }
};