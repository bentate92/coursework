
/**********************************************************************
 ** Program Filename: Queue.hpp
 ** Author: Benjamin Tate
 ** Date: 2/28/16
 ** Description: Declaration of the Queue class, which will be used by
 **   Tournament class to make teams to battle each other
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "Barbarian.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "Potter.hpp"
#include "BlueMen.hpp"
#include <iostream>

/*
 * Creation of Queue class
 * See Queue.cpp for full descriptions of functions and data members.
 */
class Queue {
  private:
    struct QueueNode {
      Creature* nodeVal;
      QueueNode* next;

      QueueNode(Creature* val1, QueueNode* next1 = NULL) {
        nodeVal = val1;
        next = next1;
      }
    };

    QueueNode* front;
    QueueNode* back;

    int queueSize;

  public:
    Queue();
    void add(Creature*);
    Creature* remove();

    int getSize();
};

#endif
