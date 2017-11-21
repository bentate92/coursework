
/**********************************************************************
 ** Program Filename: Baggage.cpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Implementation of the Baggage class, described in
 **   Baggage.hpp
 ** Input: None
 ** Output: None
 *********************************************************************/

#include "Baggage.hpp"
using namespace std;

/**********************************************************************
 ** Function: Constructor -- Baggage()
 ** Description: Creates necessary Car objects, creates Train object,
 **   runs game(train)
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
Baggage::Baggage(string name) : Car() {
  carName = name;

  entrance = "\nThe baggage car is full of the biggest, most expensive belongings of the passengers'. Boy howdy. Now's not the time for this, though. The guards are mobilizing. Go outside and see what you can do about them.";
}

/**********************************************************************
 ** Function: inspect()
 ** Description: Prints responses to certain strings
 ** Parameters: String of what to inspect
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
string Baggage::inspect(string inspection) {
  string inv;

  if(inspection == "loot") {
    cout << "\nThere's the loot, just like your employer said." << endl;
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
void Baggage::use(string item) {
  if(item == "key") {
    cout << "\nThere's nothing to unlock in here." << endl;
  }
  else if(item == "whiskey") {
    cout << "\nNow might not be the best time for a drink." << endl;
  }
}
