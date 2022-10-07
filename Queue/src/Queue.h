#pragma once
#include <memory>
using std::unique_ptr;
using std::make_unique;

template<class t_Data> class Queue {
  struct Node {
    t_Data data;
    unique_ptr<Node> nextNode;

    Node(const t_Data &_data): data(_data){}
  };

  unique_ptr<Node> firstNode;
  Node *lastNode = nullptr;
  int count = 0;

public:
  bool isEmpty() const {
    return firstNode == nullptr;
  }

  int size() const {
    return count;
  }

  // O(1)
  void enqueue(const t_Data &newData) {
    ++count;
    Node *oldLastNode = lastNode;
    auto newLastNode = make_unique<Node>(newData);
    lastNode = newLastNode.get();

    if (isEmpty()) {
      firstNode = std::move(newLastNode);
    } else {
      oldLastNode -> nextNode = std::move(newLastNode);
    }
  }

  // O(1)
  t_Data dequeue() {

    if (isEmpty()) throw std::out_of_range("Queue is empty!");
    --count;

    // Remove first item and update the references
    t_Data dataToDequeue = std::move(firstNode -> data);
    unique_ptr<Node> temp = std::move(firstNode -> nextNode);
    firstNode = std::move(temp);

    // If we call dequeue() with only 1 item on the queue
    if (isEmpty()) lastNode = nullptr;

    return dataToDequeue;
  }
};