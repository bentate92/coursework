
/**********************************************************************
 ** Program Filename: Passenger.cpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Implementation of the Passenger class, described in
 **   Passenger.hpp
 ** Input: None
 ** Output: None
 *********************************************************************/

#include "Passenger.hpp"
using namespace std;

/**********************************************************************
 ** Function: Constructor -- Passenger()
 ** Description: Creates necessary Car objects, creates Train object,
 **   runs game(train)
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
Passenger::Passenger(string name) : Car() {
  carName = name;
  
  if(carName == "passenger car 3") {
    entrance = "\nSomething isn't right... Your employer told you that this would be a passenger car, but it's filled to the brim with law men. You smile and tell them that you must have gotten turned around.";

    extraCondition = true;
  }
  else {
    entrance =  "\nYou walk into " + carName + ". It's just your typical passenger car. Everyone's pretty quiet at this point in the ride. There's a bathroom in the corner, but you've never really wanted to see the inside of a train-john.There are bags full of who knows what kind of valuables all over, but you promised your employer that you wouldn't attract any unwanted attention by stealing anything he didn't tell you to.";
  }
}

/**********************************************************************
 ** Function: inspect()
 ** Description: Prints responses to certain strings
 ** Parameters: String of what to inspect
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
string Passenger::inspect(string inspection) {
  string inv;

  if(extraCondition) {
    cout << "\nYou really shouldn't be drawing any unnecessary attention. Just get out." << endl;
  }
  else {
    if(inspection == "bathroom") {
      cout << "\nThere's a narrow little door that leads into the bathroom. In all of the trains you've robbed, you've never been inside one of the bathrooms. You try not to imagine the horrors behind this narrow little door." << endl;
    }
    else if(inspection == "bag" || inspection == "bags") {
      cout << "\nAll the bags around here look plump with valuables, and some of them aren't even being attended to. You should keep your eyes on the prize, though. The payout you're after is worth more than the contents of all of these bags together." << endl;
    }
    else if(inspection == "passengers") {
      cout << "\nThese people lead such padded lives. Just looking at them in their ten-dollar suits and shiny buttons makes you a little sick. Do you really want to join them after this job?" << endl;
    }
    else {
      cout << "\nInspect what now?" << endl;
    }
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
void Passenger::use(string item) {
  if(extraCondition) {
    cout << "\nYou don't have anything that can take on this many guards. You should leave." << endl;
  }
  else {
    if(item == "key") {
      cout << "\nThere's nothing to unlock in here." << endl;
    }
    else if(item == "whiskey") {
      cout << "\nNow might not be the best time for a drink." << endl;
    }
  }
}
