
/**********************************************************************
 ** Program Filename: List.hpp
 ** Author: Benjamin Tate
 ** Date: 1/31/16
 ** Description: Declaration of the List class, which will keep track
 **   of our Item objects
 ** Input: none
 ** Output: none
 *********************************************************************/

#ifndef LIST_HPP
#define LIST_HPP

#include "Item.hpp"
#include <iostream>

using namespace std;

/* 
 * Creation of List class
 * See List.cpp for full descriptions of functions and data members.
 */
class List {
  private:
    int len;
    Item* list;
    int numItems;

  public:
    List();
    void add(Item);
    void remove(Item);
    void displayList();

    void deleteList();
};

#endif
