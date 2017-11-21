
/**********************************************************************
 ** Program Filename: Creature.cpp
 ** Author: Benjamin Tate
 ** Date: 2/28/16
 ** Description: Implementation of the Creature class, described in
 **   Creature.hpp
 ** Input: none
 ** Output: none
 *********************************************************************/

#include "Creature.hpp"

using namespace std;

/**********************************************************************
 ** Function: Constructor -- Creature()
 ** Description: Sets attSides, attcount, defSides, defCount, armor, 
 **   and strength to their appropriate values, initializes score to 0
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
  startingStr = health;
  strength = health;
  score = 0;
}

/**********************************************************************
 ** Function: getId()
 ** Description: Returns a Creature's ID# for type identification 
 **   outside of class
 ** Parameters: None
 ** Pre-Conditions: Proper id must be set
 ** Post-Conditions: None
 *********************************************************************/
int Creature::getId() {
  return id;
}

/**********************************************************************
 ** Function: getName()
 ** Description: Returns a Creature's name
 ** Parameters: None
 ** Pre-Conditions: creatureName must be set by user or main function
 ** Post-Conditions: None
 *********************************************************************/
string Creature::getName() {
  return creatureName;
}

/**********************************************************************
 ** Function: getAtt()
 ** Description: Returns a Creature's attack for the given turn
 ** Parameters: None
 ** Pre-Conditions: att must be set by a Creature's attack() function
 ** Post-Conditions: None
 *********************************************************************/
int Creature::getAtt() {
  return att;
}

/**********************************************************************
 ** Function: getDef()
 ** Description: Returns a Creature's defense for the given turn
 ** Parameters: None
 ** Pre-Conditions: def must be set by a Creature's defend() function
 ** Post-Conditions: None
 *********************************************************************/
int Creature::getDef() {
  return def + armor;
}

/**********************************************************************
 ** Function: getStr()
 ** Description: Returns a Creature's current remaining strength
 ** Parameters: None
 ** Pre-Conditions: Creature must be initialized with strength value
 ** Post-Conditions: None
 *********************************************************************/
int Creature::getStr() {
  return strength;
}

/**********************************************************************
 ** Function: getScore()
 ** Description: Returns a Creature's current score
 ** Parameters: None
 ** Pre-Conditions: score must be set
 ** Post-Conditions: None
 *********************************************************************/
int Creature::getScore() {
  return score;
}

/**********************************************************************
 ** Function: victory()
 ** Description: Heals random percentage of totalDamage from 20-100%,
 **   rounding down, increments score
 ** Parameters: None
 ** Pre-Conditions: Creature must have up-to-date strength value, as
 **   well as a value for startingStr
 ** Post-Conditions: None
 *********************************************************************/
void Creature::victory() {
  /*Initialize roll, healDouble, and heal*/
  int roll;
  double healDouble;
  int heal;
  /*Set totalDamage*/
  totalDamage = startingStr - strength;

  /*Set roll randomly between 1 and 20*/
  roll = rand() % 20 + 1;
  /*Set healDouble as the product of roll and totalDamage / 20*/
  healDouble = roll * totalDamage * 0.05;
  /*Round healDouble down for heal*/
  heal = floor(healDouble);

  /*Add heal to strength*/
  strength += heal;

  /*Increment score*/
  score++;
}
