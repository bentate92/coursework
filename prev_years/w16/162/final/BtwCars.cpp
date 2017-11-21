
/**********************************************************************
 ** Program Filename: BtwCars.cpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Implementation of the BtwCars class, described in
 **   BtwCars.hpp
 ** Input: None
 ** Output: None
 *********************************************************************/

#include "BtwCars.hpp"
using namespace std;

/**********************************************************************
 ** Function: Constructor -- BtwCars()
 ** Description: Creates necessary Car objects, creates Train object,
 **   runs game(train)
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
BtwCars::BtwCars(string name) : Car() {
  carName = name;

  entrance = "\nYou find yourself on the small landing between passenger car 3 and the baggage car. You try to quietly open the door to the baggage car, but you find that it's locked. Your employer didn't say anything about this.";
}

/**********************************************************************
 ** Function: inspect()
 ** Description: Prints responses to certain strings
 ** Parameters: String of what to inspect
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
string BtwCars::inspect(string inspection) {
  string inv;

  if(inspection == "latch") {
    cout << "\nYou pull the pin in the latch much more easily than you thought you'd be able to. You smile and wave at the guards as your car separates from the rest of the train. That's that!\n" << endl;

    inv = "end";
  }
  else if(inspection == "door") {
    cout << "\nIt's locked up tight" << endl;
  }
  else if(inspection == "lock") {
    cout << "\nYou can't pick it" << endl;
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
void BtwCars::use(string item) {
  if(item == "key") {
    cout << "\nYou try the engineer's key on the door. 'It worked!' you hear yourself exclaim outlout. A guard must have heard you, because he looks out of his car and alerts the rest that you've broken into the baggage car. You notice that the latch holding the baggage car to the rest of the train seems loose." << endl;
  }
  else if(item == "whiskey") {
    cout << "\nNow might not be the best time for a drink." << endl;
  }
}
