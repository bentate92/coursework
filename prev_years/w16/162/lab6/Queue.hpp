
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

class Queue {
  private:
    struct QueueNode {
      int nodeVal;
      QueueNode *next;

      QueueNode(int val1, QueueNode *next1 = NULL) {
        nodeVal = val1;
        next = next1;
      }
    };

    QueueNode *front;
    QueueNode *back;

  public:
    Queue();
    Queue(int);
//    ~Queue();
    void add(int);
    int remove();
};

#endif
