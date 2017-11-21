
/**********************************************************************
 ** Program Filename: Bathroom.cpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Implementation of the Bathroom class, described in
 **   Bathroom.hpp
 ** Input: None
 ** Output: None
 *********************************************************************/

#include "Bathroom.hpp"
using namespace std;

/**********************************************************************
 ** Function: Constructor -- Bathroom()
 ** Description: Creates necessary Car objects, creates Train object,
 **   runs game(train)
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
Bathroom::Bathroom(string name) : Car() {
  carName = name;

  entrance = "\nYou enter the bathroom, which basically amounts to a hole in the floor of train. Gross.";
}

/**********************************************************************
 ** Function: inspect()
 ** Description: Prints responses to certain strings
 ** Parameters: String of what to inspect
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
string Bathroom::inspect(string inspection) {
  string inv;

  if(inspection == "toilet" || inspection == "hole") {
    cout << "\nIt's basically just a hole." << endl;
  }
  else if(inspection == "sink") {
    cout << "\nThere is none." << endl;
  }
  else if(inspection == "soap") {
    cout << "\nNone to speak of." << endl;
  }
  else if(inspection == "hand sanitizer") {
    cout << "\nWhat is that?" << endl;
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
void Bathroom::use(string item) {
  if(item == "key") {
    cout << "\nThere's nothing to unlock in here. You're extra careful not to drop it." << endl;
  }
  else if(item == "whiskey") {
    cout << "\nYou aren't sure you could enjoy it in here." << endl;
  }
}
