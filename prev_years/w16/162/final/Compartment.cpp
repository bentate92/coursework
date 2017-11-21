
/**********************************************************************
 ** Program Filename: Compartment.cpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Implementation of the Compartment class, described in
 **   Compartment.hpp
 ** Input: None
 ** Output: None
 *********************************************************************/

#include "Compartment.hpp"
using namespace std;

/**********************************************************************
 ** Function: Constructor -- Compartment()
 ** Description: Creates necessary Car objects, creates Train object,
 **   runs game(train)
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
Compartment::Compartment(string name) : Car() {
  carName = name;
 
  checkCount = 0;
 
  entrance = "\nYou crawl down into the cramped compartment. There's hardly any space to move, and you have to be almost totally prone to fit at all. The only thing in here is a bag that presumably belongs to the engineer.";
}

/**********************************************************************
 ** Function: inspect()
 ** Description: Prints responses to certain strings
 ** Parameters: String of what to inspect
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
string Compartment::inspect(string inspection) {
  string inv;

  if(inspection == "bag") {
    if(checkCount == 0) {
      cout << "\nThere's really nothing of note in here except a plain looking key. You don't know what it unlocks, but it might be useful, so you take it." << endl;

      inv = "key";

      checkCount++;
    }
    else {
      cout << "\nThere's nothing left worth taking in here." << endl;
    }
  }
  else {
    cout << "\nInspect what now?" << endl;
  }

  return inv;
}
 
/**********************************************************************
 ** Function: use()
 ** Description: Prints responses to certain strings
 ** Parameters: String of what to use
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
void Compartment::use(string item) {
  if(item == "key") {
    cout << "\nThere's nothing to unlock in here." << endl;
  }
  else if(item == "whiskey") {
    cout << "\nNow might not be the best time for a drink." << endl;
  }
}
