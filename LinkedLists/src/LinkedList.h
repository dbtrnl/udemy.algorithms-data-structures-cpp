#pragma once

#include "List.h"
#include <memory>
#include <iostream>

template<class t_Data>
class LinkedList : public List<t_Data> {
  struct Node {
    t_Data data;
    std::unique_ptr<Node> nextNode; // Unique pointers automatically free the memory
    Node(const t_Data &_data): data(_data){}
  };
  
  int sizeCounter = 0;
  std::unique_ptr<Node> head;

public:
  LinkedList() = default;
  void insert(const t_Data &data) override {
    ++sizeCounter;
    insertDataHead(data);
  }
  
  void remove(const t_Data &data) override {
    // If empty list
    if (!head) return;

    // If head is to be removed - O(1)
    if (head->data == data) {
      auto newHead = std::move(head->nextNode);
      head = std::move(newHead);
      --sizeCounter;
      return;
    }

    if (!head->nextNode) {
      std::cout << data << " is not found in this list!";
      return;
    }

    // Initializing helper nodes (these pointers use unique_ptr, so no need to manage that);
    Node *prev = head.get();
    Node *next = head->nextNode.get();

    // Iterating through all nodes
    while (next->data != data) {
      prev = next;
      next = next->nextNode.get();
    }

    // If all nodes were traversed
    if (!next) {
      std::cout << data << " is not found in this list!";
      return;
    }

    // Previous node will point to the next node
    std::unique_ptr<Node> temp = std::move(next->nextNode);
    prev->nextNode = std::move(temp);
  }

  void traverseList() const override {
		Node *node = head.get();

		// while node is not null, data is printed
		while (node) {
			std::cout << node->data << ' ';
			node = node->nextNode.get();
		}
		std::cout << '\n';
  }

  int size() const override {
		return sizeCounter;
	}

private:
  // O(1) time complexity
  void insertDataHead(const t_Data &data) {
    std::unique_ptr<Node> newNode = std::make_unique<Node>(data);
    newNode->nextNode = std::move(head);
    head = std::move(newNode);
  }
};
