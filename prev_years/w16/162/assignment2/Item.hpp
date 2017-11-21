
/**********************************************************************
 ** Program Filename: Item.hpp
 ** Author: Benjamin Tate
 ** Date: 1/31/16
 ** Description: Declaration of Item class, which will be used to store
 **   the name, unit of sale, unit price, and quantity needed for an
 **   item in our list
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef ITEMS_HPP
#define ITEMS_HPP

#include <string>

using namespace std;

/*
 * Creation of Item class
 * See Item.cpp for full descriptions of functions and data members.
 */
class Item {
  private:
    string name;
    string unit;
    double price;
    int quantity;

  public:
    Item();
    Item(string, string, double, int);

    string getName();
    string getUnit();
    double getPrice();
    int getQuantity();
    
    void changeQuantity(int);

    friend bool operator== (Item, Item);
};

#endif
