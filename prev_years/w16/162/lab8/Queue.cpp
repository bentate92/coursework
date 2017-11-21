
/**********************************************************************
 ** Program Filename: Queue.cpp
 ** Author: Benjamin Tate
 ** Date: 2/28/16
 ** Description: Implementation of the Queue class, described in
 **   Queue.hpp
 ** Input: None
 ** Output: None
 *********************************************************************/

#include "Queue.hpp"
using namespace std;

/**********************************************************************
 ** Function: Default constructor -- Queue()
 ** Description: Initializes Queue with one node, containing the 
 **   sentinal value -1, sets its next and prev pointers to point to
 **   itself, and sets front and back QueueNode pointers to it
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
Queue::Queue() {
  /*Initialize header as a new default QueueNode*/
  header = new QueueNode;
  /*Assign header to front and back*/
  front = header;
  back = header;
  /*Set back and front to point to each other to make list circular*/
  back->next = front;
  front->prev = back;
}

/**********************************************************************
 ** Function: addBack()
 ** Description: Changes the value of the node behind back if it is
 **   empty, and creates a new QueueNode with newest value if the 
 **   Queue is full
 ** Parameters: One int representing the value being added to the Queue
 ** Pre-Conditions: Newest must exist and contain a value, back must 
 **   point to a non-null QueueNode
 ** Post-Conditions: None
 *********************************************************************/
void Queue::addBack(int newest) {
  /*If there is an empty node after back*/
  if(back->next->nodeVal == -1) {
    /*Update its value*/
    back->next->nodeVal = newest;
    /*Update back pointer*/
    back = back->next;
  }
  /*If the queue is full*/
  else {
    /*Create new node after back*/
    back->next = new QueueNode(newest, back, back->next);
    /*Update back pointer*/
    back = back->next;  
    /*Set back->next to front*/
    back->next = front; 
  }
}

/**********************************************************************
 ** Function: removeFront()
 ** Description: Removes and returns the int at the front of the line
 ** Parameters: None
 ** Pre-Conditions: front must point to a non-null QueueNode
 ** Post-Conditions: None
 *********************************************************************/
int Queue::removeFront() {
  /*Create int variable to hold value of front node*/
  int frontVal = front->nodeVal;
  /*Remove value from front*/
  front->nodeVal = -1;
  /*Update front pointer*/
  front = front->next;

  return frontVal;
}

/**********************************************************************
 ** Function: getFront()
 ** Description: Returns the int at the front of the line
 ** Parameters: None
 ** Pre-Conditions: front must point to a non-null QueueNode
 ** Post-Conditions: None
 *********************************************************************/
int Queue::getFront() {
  return front->nodeVal;
}

