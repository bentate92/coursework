
/**********************************************************************
 ** Program Filename: listMain.cpp
 ** Author: Benjamin Tate
 ** Date: 1/31/16
 ** Description: Main function to provide user prompts and create and 
 **   interact with necessary objects
 ** Input: none
 ** Output: none
 *********************************************************************/

#include "List.hpp"

using namespace std;

int main() {
  /*Create List object*/
  List userList;

  /*Create string to hold the name for an Item object*/
  string itemName;
  /*Create string to hold the unit for an Item object*/
  string itemUnits;
  /*Create double to hold the price for an Item object*/
  double unitPrice;
  /*Create int to hold the quantity for an Item object*/
  int itemQuantity;

  /*Introduce program's purpose*/
  cout << "We're going to make a few items and add them to a grocery list.\n"
       << endl;

  /*
   * Item1 --
   */
  /*Provide prompts and store user selections in appropriate variables*/
  cout << "Let's add the first item to our list." << endl;
  cout << "To start, what is the name of the item?" << endl;
  cin >> itemName;

  cout << "Next, what is the unit of sale for this item?" << endl;
  cin >> itemUnits;
  
  cout << "And what is the price per unit? (up to two decimal places)" 
       << endl;
  cin >> unitPrice;

  cout << "Finally, how many units of this item would you like to add?" 
       << endl;
  cin >> itemQuantity;

  /*Create item1, using user responses*/
  Item item1(itemName, itemUnits, unitPrice, itemQuantity);
  
  /*Add item1 to userList*/
  userList.add(item1); 

  /*
   * Item2 -- repeat steps from Item1
   */
  cout << "\nLet's make another!" << endl;
  cout << "What is the name of the item?" << endl;
  cin >> itemName;

  cout << "Next, what is the unit of sale for this item?" << endl;
  cin >> itemUnits;
  
  cout << "And what is the price per unit? (up to two decimal places)" 
       << endl;
  cin >> unitPrice;

  cout << "Finally, how many units of this item would you like to add?"
       << endl;
  cin >> itemQuantity;

  Item item2(itemName, itemUnits, unitPrice, itemQuantity);
  
  userList.add(item2); 

  /*
   * Item3 -- repeat steps from Item1
   */
  cout << "\nLet's make another!" << endl;
  cout << "What is the name of the item?" << endl;
  cin >> itemName;

  cout << "Next, what is the unit of sale for this item?" << endl;
  cin >> itemUnits;
  
  cout << "And what is the price per unit? (up to two decimal places)"
       << endl;
  cin >> unitPrice;

  cout << "Finally, how many units of this item would you like to add?"
       << endl;
  cin >> itemQuantity;

  Item item3(itemName, itemUnits, unitPrice, itemQuantity);
  
  userList.add(item3); 

  /*
   * Item4 -- repeat steps from Item1
   */
  cout << "\nLet's make another!" << endl;
  cout << "What is the name of the item?" << endl;
  cin >> itemName;

  cout << "Next, what is the unit of sale for this item?" << endl;
  cin >> itemUnits;
  
  cout << "And what is the price per unit? (up to two decimal places)"
       << endl;
  cin >> unitPrice;

  cout << "Finally, how many units of this item would you like to add?"
       << endl;
  cin >> itemQuantity;

  Item item4(itemName, itemUnits, unitPrice, itemQuantity);
  
  userList.add(item4); 

  /*
   * Item5 -- repeat steps from Item1
   */
  cout << "\nLet's make another! (This one will require that the list" <<
          "be resized)" << endl;
  cout << "What is the name of the item?" << endl;
  cin >> itemName;

  cout << "Next, what is the unit of sale for this item?" << endl;
  cin >> itemUnits;
  
  cout << "And what is the price per unit? (up to two decimal places)"
       << endl;
  cin >> unitPrice;

  cout << "Finally, how many units of this item would you like to add?"
       << endl;
  cin >> itemQuantity;

  Item item5(itemName, itemUnits, unitPrice, itemQuantity);
  
  userList.add(item5); 


  /*Display current list*/
  cout << "\nHere is the list currently:" << endl;
  userList.displayList();

  /*Initialize int to hold user selection for Item removal*/
  int itemRemove;

  /*Prompt user to select Item to remove*/
  cout << "\nLet's try removing an item. Which would you like to remove?" <<
          "(enter 1-5)" << endl;
  cin >> itemRemove;

  /*Remove Item that corresponds to user selection*/
  if(itemRemove == 1) {
    userList.remove(item1);
  }
  else if(itemRemove == 2) {
    userList.remove(item2);
  } 
  else if(itemRemove == 3) {
    userList.remove(item3);
  } 
  else if(itemRemove == 4) {
    userList.remove(item4);
  } 
  else if(itemRemove == 5) {
    userList.remove(item5);
  } 
 
  /*Print success*/ 
  cout << "\nItem " << itemRemove << " removed! Here is the final list:"
       << endl;
  
  /*Display new list*/
  userList.displayList();

  /*Delete dynamic array to free memory*/
  userList.deleteList();
}
