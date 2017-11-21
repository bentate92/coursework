
/**********************************************************************
 ** Program Filename: Dining.cpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Implementation of the Dining class, described in
 **   Dining.hpp
 ** Input: None
 ** Output: None
 *********************************************************************/

#include "Dining.hpp"
using namespace std;

/**********************************************************************
 ** Function: Constructor -- Dining()
 ** Description: Creates necessary Car objects, creates Train object,
 **   runs game(train)
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
Dining::Dining(string name) : Car() {
  carName = name;

  checkCount = 0;

  entrance = "\nThere's a bunch of rich folks eating in this fancy dining car. A few of them are drinking coffee and smoking big cigars. There's a fully-stocked bar in the corner.";
}

/**********************************************************************
 ** Function: inspect()
 ** Description: Prints responses to certain strings
 ** Parameters: String of what to inspect
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
string Dining::inspect(string inspection) {
  string inv;

  if(inspection == "bar" && checkCount == 0) {
    cout << "\nThere's a nice bottle of whiskey sitting on the bar, and the bartender seems distracted by a woman at the opposite end. You told your employer you wouldn't take anything besides what you came for, but this is too good to pass up. You swipe the whiskey and put it in your bag." << endl;

    inv = "whiskey";

    checkCount++;
  }
  else if(inspection == "people") {
    cout << "\nYup... They're rich." << endl;
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
void Dining::use(string item) {
  if(item == "key") {
    cout << "\nThere's nothing to unlock in here." << endl;
  }
  else if(item == "whiskey") {
    cout << "\nNow might not be the best time for a drink. The bartender might notice." << endl;
  }
}
