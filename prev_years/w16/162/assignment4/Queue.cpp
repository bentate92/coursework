
/**********************************************************************
 ** Program Filename: Queue.hpp
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
 ** Description: Sets front and back pointers to NULL, initializes
 **   queueSize to 0
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
Queue::Queue() {
  front = NULL;
  back = NULL;
  queueSize = 0;
}

/**********************************************************************
 ** Function: add()
 ** Description: Adds a Creature pointer to the back of the line
 ** Parameters: One pointer to a Creature to be added
 ** Pre-Conditions: Newest must contain a non-NULL creature
 ** Post-Conditions: None
 *********************************************************************/
void Queue::add(Creature* newest){
  /*If Queue is empty, set new QueueNode to front and back*/
  if(front == NULL) {
    front = new QueueNode(newest);
    back = front;
  }
  /*
   * Otherwise, set the place after back to new QueueNode and then set
   * that to back
   */
  else {
    back->next = new QueueNode(newest);
    back = back->next;
  }

  /*Increment queueSize*/
  queueSize++;
}

/**********************************************************************
 ** Function: remove()
 ** Description: Removes and returns the Creature at the front of the line
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
Creature* Queue::remove()
{
  /*Initialize frontFighter Creature*/
  Creature* frontFighter;
  /*Initialize temp QueueNode*/
  QueueNode* temp;

  /*Shuffle Queue members appropriately*/
  if(front == NULL) {
    /*If Queue is empty, tell user*/
    cout << "No fighters in this Queue!" << endl;
  }
  else {
    /*Set frontFighter to front nodeVal*/
    frontFighter = front->nodeVal;
    /*Set temp to front*/
    temp = front;
    /*Set front to the next value in line*/
    front = temp->next;
    /*Delete temp*/
    delete temp;

    /*Decrease queueSize*/
    queueSize--;
  }

  return frontFighter;
}

/**********************************************************************
 ** Function: getSize()
 ** Description: Returns the current size of the Queue
 ** Parameters: None
 ** Pre-Conditions: queueSize must be initialized
 ** Post-Conditions: None
 *********************************************************************/
int Queue::getSize() {
  return queueSize;
}

