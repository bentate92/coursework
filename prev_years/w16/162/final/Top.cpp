
/**********************************************************************
 ** Program Filename: Engine.cpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Implementation of the Engine class, described in
 **   Engine.hpp
 ** Input: None
 ** Output: None
 *********************************************************************/

#include "Top.hpp"
using namespace std;

/**********************************************************************
 ** Function: Constructor -- Engine()
 ** Description: Creates necessary Car objects, creates Train object,
 **   runs game(train)
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
Top::Top(string name) : Car() {
  carName = name;

  entrance = "\nYou find yourself on the " + carName + ". There really isn't much to look at up here, and it's very shaky. Better get moving";
}

/**********************************************************************
 ** Function: inspect()
 ** Description: Prints responses to certain strings
 ** Parameters: String of what to inspect
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
string Top::inspect(string inspection) {
  string inv;

  cout << "\nThere really isn't anything up here." << endl;

  return inv;
}

/**********************************************************************
 ** Function: use()
 ** Description: Prints responses to certain strings
 ** Parameters: String of what to use
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
void Top::use(string item) {
  if(item == "key") {
    cout << "\nThere's nothing to unlock in here." << endl;
  }
  else if(item == "whiskey") {
    cout << "\nNow might not be the best time for a drink." << endl;
  }
}
