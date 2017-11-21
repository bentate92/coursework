
#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

class Stack {
  private:
    struct StackNode {
      int nodeVal;
      StackNode *next;
    
      StackNode(int val1, StackNode *next1 = NULL) {
        nodeVal = val1;
        next = next1;
      }
    };

    StackNode *head;

  public:
    Stack();
    Stack(int);
    void add(int);
    int remove();
};

#endif
