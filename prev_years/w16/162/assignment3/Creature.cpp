
/**********************************************************************
 ** Program Filename: Creature.cpp
 ** Author: Benjamin Tate
 ** Date: 2/14/16
 ** Description: Implementation of the Creature class, described in
 **   Creature.hpp
 ** Input: none
 ** Output: none
 *********************************************************************/

#include "Creature.hpp"

/**********************************************************************
 ** Function: Constructor -- Creature()
 ** Description: Sets attSides, attcount, defSides, defCount, armor, 
 **   and strength to their appropriate values
 ** Parameters: 6 ints, representing above mentioned variables,
 **   received from derived class constructors
 ** Pre-Conditions: Parameter variables must exist and contain values
 ** Post-Conditions: None
 *********************************************************************/
Creature::Creature(int aSides, int aCount, int dSides, int dCount, int shield, int health) {
  attSides = aSides;
  attCount = aCount;
  defSides = dSides;
  defCount = dCount;
  armor = shield;
  strength = health;
}

/**********************************************************************
 ** Function: getAtt()
 ** Description: Return's a Creature's attack for the given turn
 ** Parameters: None
 ** Pre-Conditions: att must be set by a Creature's attack() function
 ** Post-Conditions: None
 *********************************************************************/
int Creature::getAtt() {
  return att;
}

/**********************************************************************
 ** Function: getDef()
 ** Description: Return's a Creature's defense for the given turn
 ** Parameters: None
 ** Pre-Conditions: def must be set by a Creature's defend() function
 ** Post-Conditions: None
 *********************************************************************/
int Creature::getDef() {
  return def + armor;
}

/**********************************************************************
 ** Function: getStr()
 ** Description: Return's a Creature's current remaining strength
 ** Parameters: None
 ** Pre-Conditions: Creature must be initialized with strength value
 ** Post-Conditions: None
 *********************************************************************/
int Creature::getStr() {
  return strength;
}
