
/**********************************************************************
 ** Program Filename: Queue.hpp
 ** Author: Benjamin Tate
 ** Date: 2/28/16
 ** Description: Declaration of the Queue class, which will create a
 **   doubly-linked, circular list and allow manipulation and display
 **   of said list
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <string>

/*
 * Creation of Queue class
 * See Queue.cpp for full descriptions of functions and data members.
 */
class Queue {
  private:
    struct QueueNode {
      /*Initialize int to hold the node's value*/
      int nodeVal;
      /*Create pointers to hold locations of next and previous nodes*/
      QueueNode* next;
      QueueNode* prev;

      /*
       * By default, create node with sentinal value whose next and prev
       * point to itself
       */
      QueueNode() {
        nodeVal = -1;
        prev = this;
        next = this;
      }
      /*Accept parameters for nodeVal, next and prev, update pointers*/
      QueueNode(int val, QueueNode* prev, QueueNode* next) {
        nodeVal = val;
        prev = prev;
        next = next;

        prev->next = this;
        next->prev = this;
      }
      /*Remove this node when finished*/
      ~QueueNode() {
        prev->next = next;
        next->prev = prev;
      }
    };
    
    QueueNode* header;
    QueueNode* front;
    QueueNode* back;

  public:
    Queue();
    void addBack(int);
    int removeFront();
    int getFront();
    bool isEmpty();
};

#endif
