
/**********************************************************************
 ** Program Filename: Stack.hpp
 ** Author: Benjamin Tate
 ** Date: 2/28/16
 ** Description: Implementation of the Stack class, described in
 **   Stack.hpp
 ** Input: None
 ** Output: None
 *********************************************************************/

#include "Stack.hpp"

using namespace std;

/**********************************************************************
 ** Function: Default constructor -- Stack()
 ** Description: Sets head pointer to NULL, initializes stackSize to 0
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
Stack::Stack() {
  head = NULL;
  stackSize = 0;
}

/**********************************************************************
 ** Function: add()
 ** Description: Adds a Creature pointer to the top of the pile
 ** Parameters: One pointer to a Creature to be added
 ** Pre-Conditions: Newest must contain a non-NULL creature
 ** Post-Conditions: None
 *********************************************************************/
void Stack::add(Creature* newest) {
  /*Set head to new StackNode*/
  head = new StackNode(newest, head);
  
  /*Increment stackSize*/
  stackSize++;
}

/**********************************************************************
 ** Function: remove()
 ** Description: Removes and returns the Creature at the top of the pile
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
Creature* Stack::remove() {
  /*Initialize topFighter Creature*/
  Creature* topFighter;
  /*Initialize temp StackNode*/
  StackNode* temp;

  /*Shuffle Stack members appropriately*/
  if(head == NULL) {
    /*If Stack is empty, tell user*/
    cout << "No fighters in this Stack!" << endl;
  } 
  else {
    /*Set topFighter to front nodeVal*/
    topFighter = head->nodeVal;
    /*Set temp to head*/  
    temp = head;
    /*Set head to the next value in pile*/
    head = head->next;
    /*Delete temp*/
    delete temp;

    /*Decrease stackSize*/ 
    stackSize--;
  }

  return topFighter;
}

/**********************************************************************
 ** Function: getSize()
 ** Description: Returns the current size of the Stack
 ** Parameters: None
 ** Pre-Conditions: stackSize must be initialized
 ** Post-Conditions: None
 *********************************************************************/
int Stack::getSize() {
  return stackSize;
}


