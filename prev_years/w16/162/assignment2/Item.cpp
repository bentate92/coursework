
/**********************************************************************
 ** Program Filename: Item.cpp
 ** Author: Benjamin Tate
 ** Date: 1/31/16
 ** Description: Implementation of the Item class, described in
 **   Item.hpp
 ** Input: none
 ** Output: none
 *********************************************************************/

#include "Item.hpp"

/**********************************************************************
 ** Function: Default constructor -- Item()
 ** Description: Sets name and unit to blank, and price and quantity to
 **   zero
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
Item::Item() {
  name = "";
  unit = "";
  price = 0.00;
  quantity = 0;
}

/**********************************************************************
 ** Function: Constructor -- Item()
 ** Description: Sets name, unit, price, and quantity to corresponding
 **   user-selected values
 ** Parameters: Two strings for name and unit, a double for the price
 **   per unit, and an int for the quantity
 ** Pre-Conditions: Parameters must contain values
 ** Post-Conditions: None
 *********************************************************************/
Item::Item(string itemName, string itemUnits, 
           double unitPrice, int itemQuantity) {
  name = itemName;
  unit = itemUnits;
  price = unitPrice;
  quantity = itemQuantity;
}

/**********************************************************************
 ** Function: getName()
 ** Description: Returns name for access outside of Item class
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
string Item::getName() {
  return name;
}

/**********************************************************************
 ** Function: getUnit()
 ** Description: Returns unit for access outside of Item class
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
string Item::getUnit() {
  return unit;
}

/**********************************************************************
 ** Function: getPrice()
 ** Description: Returns price for access outside of Item class
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
double Item::getPrice() {
  return price;
}

/**********************************************************************
 ** Function: getQuantity()
 ** Description: Returns quantity for access outside of Item class
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
int Item::getQuantity() {
  return quantity;
}

/**********************************************************************
 ** Function: changeQuantity()
 ** Description: Alters the quantity of the Item
 ** Parameters: An integer to add to the current quantity
 ** Pre-Conditions: Must be a current quantity
 ** Post-Conditions: None
 *********************************************************************/
void Item::changeQuantity(int addition) {
  quantity += addition;
}

/**********************************************************************
 ** Function: overload of operator==
 ** Description: Returns true if both the name and unit match for two 
 **   given Items
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
bool operator== (Item LHS, Item RHS) {
  return LHS.getName() == RHS.getName() &&
         LHS.getUnit() == RHS.getUnit();
}
