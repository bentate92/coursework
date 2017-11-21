
/**********************************************************************
 ** Program Filename: Stack.hpp
 ** Author: Benjamin Tate
 ** Date: 2/28/16
 ** Description: Declaration of the Stack class, which be used to create
 **   a loser pile for the Tournament
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#include "Barbarian.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "Potter.hpp"
#include "BlueMen.hpp"
#include <iostream>

/*
 * Creation of Stack class
 * See Stack.cpp for full descriptions of functions and data members.
 */
class Stack {
  private:
    struct StackNode {
      Creature *nodeVal;
      StackNode *next;
    
      StackNode(Creature *val1, StackNode *next1 = NULL) {
        nodeVal = val1;
        next = next1;
      }
    };

    StackNode *head;

    int stackSize;

  public:
    Stack();
    void add(Creature*);
    Creature* remove();

    int getSize();
};

#endif
