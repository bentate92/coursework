
/**********************************************************************
 ** Program Filename: List.cpp
 ** Author: Benjamin Tate
 ** Date: 1/31/16
 ** Description: Implementation of the List class, described in
 **   List.hpp
 ** Input: none
 ** Output: none
 *********************************************************************/

#include "List.hpp"
#include <iomanip>

using namespace std;

/**********************************************************************
 ** Function: Default constructor -- List()
 ** Description: Sets len to an initial value of 4, declares a dynamic
 **   array of Items, initializes numItems to 0
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
List::List() {
  len = 4;
  list = new Item[len];
  numItems = 0;
}

/**********************************************************************
 ** Function: add()
 ** Description: Adds a new Item to list, unless it is a duplicate of
 **   an existing one, in which case it increments the Item's quantity
 ** Parameters: A new Item object
 ** Pre-Conditions: Item parameter must exist and contain values for 
 **   name, unit, price, and quantity
 ** Post-Conditions: None
 *********************************************************************/
void List::add(Item newItem) {
  /*Iterate through existing Items in list*/
  for(int i = 0; i < numItems; i++) {
    /*If current Item in list == newItem, change quantity and stop*/
    if (list[i] == newItem) {
      list[i].changeQuantity(newItem.getQuantity());
  
      return;
    }
  }

  /*If list is at item limit, increase length of list by 4*/
  if(numItems == len) {
    /*Initialize new length*/
    int new_length = len + 4;

    /*Create new dynamic array*/
    Item* newList = new Item[new_length];

    /*Copy list to newList*/
    for(int i = 0; i < len; i++) {
      newList[i] = list[i];
    }

    /*Copy newList back into list (length updated)*/
    list = newList;

    /*Update len*/
    len = new_length;
  }

  /*Add newItem to next position in list*/
  list[numItems] = newItem;
  
  /*Increment numItems*/
  numItems++;

  return;
}

/**********************************************************************
 ** Function: remove()
 ** Description: Removes specified Item from list and shifts the 
 **   countents of list accordingly
 ** Parameters: One Item object
 ** Pre-Conditions: oldItem must match an Item in list
 ** Post-Conditions: None
 *********************************************************************/
void List::remove(Item oldItem) {
  /*Create temporary array*/
  Item* newArray = new Item[len];

  /*Iterate over list*/ 
  for(int i = 0; i < numItems; i++) {
    /*Shift list over from oldItem onward (removing oldItem)*/
    if(list[i] == oldItem) {
      for(int j = i; j < (numItems - 1); j++) {
        list[j] = list[j + 1];
      }
      break;
    }
  }

  /*Copy relevant elements from list to newArray, ignoring duplicate*/
  for(int i = 0; i < numItems - 1; i++) {
    newArray[i] = list[i];
  }

  /*Copy newArray to list (with duplicate Item at end removed)*/
  list = newArray;

  /*Decrease numItems by 1*/
  numItems--;
}

/**********************************************************************
 ** Function: displayList()
 ** Description: Calculates extended price for each Item in list, as
 **   well as total price for all Items in list, displays relevant
 **   values of each Item in a table, prints the total price for the
 **   list
 ** Parameters: None
 ** Pre-Conditions: At least one Item must be contained in list array
 ** Post-Conditions: None
 *********************************************************************/
void List::displayList() {
  /*Initialize two doubles for total price and extended price*/
  double totalPrice = 0.00;
  double exPrice;

  /*Print table header*/
  cout << "#|Item Name |" << "Unit of Sale |" << "Unit Price |" << 
          "Quantity |" << "Extended Price" << endl;
  cout << "-|----------|-------------|-----------|---------" <<
          "|--------------" << endl;

  /*Iterate through current list Items*/
  for(int i = 0; i < numItems; i++) {
    /*Set extended price for current Item*/
    exPrice = list[i].getPrice() * list[i].getQuantity();

    /*Print relevant values for current Item*/
    cout << i + 1 << "|" << setw(10) << list[i].getName() << "|" <<
            setw(13) << list[i].getUnit() << "|" << setw(11) << 
            list[i].getPrice() << "|" << setw(9) << 
            list[i].getQuantity() << "|" << exPrice << endl;

    /*Add Item's extended price to totalPrice*/
    totalPrice += exPrice;
  }
  /*Print total price*/
  cout << "Total Price = $" << totalPrice << endl;
}

/**********************************************************************
 ** Function: deleteList()
 ** Description: Deletes the dynamic array
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
void List::deleteList() {
  delete[] list;
}





