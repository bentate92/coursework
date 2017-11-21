
/**********************************************************************
 ** Program Filename: Car.cpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Implementation of the Car class, described in
 **   Car.hpp
 ** Input: None
 ** Output: None
 *********************************************************************/

#include "Car.hpp"
using namespace std;

/**********************************************************************
 ** Function: Default constructor -- Car()
 ** Description: Sets extraCondition to false
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
Car::Car() {
  extraCondition = false;
}

/**********************************************************************
 ** Function: getName()
 ** Description: Returns carName
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
string Car::getName() {
  return carName;
}

/**********************************************************************
 ** Function: enter()
 ** Description: Prints appropriate entrance statement
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
void Car::enter() {
  if(!newEntrance.empty()) {
    cout << "\n" << newEntrance << endl;
  }
  else {
    cout << "\n" << entrance << endl;
  }
}

/**********************************************************************
 ** Function: getExtra()
 ** Description: Returns extraCondition
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
bool Car::getExtra() {
  return extraCondition;
}

/**********************************************************************
 ** Function: getName()
 ** Description: Changes extraCondition
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
void Car::changeExtra() {
  if(!extraCondition) {
    extraCondition = true;
  }
  else {
    extraCondition = false;
  }
}
