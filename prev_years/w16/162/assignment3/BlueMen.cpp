
/**********************************************************************
 ** Program Filename: BlueMen.cpp
 ** Author: Benjamin Tate
 ** Date: 2/14/16
 ** Description: Implementation of the BlueMen class, described in
 **   BlueMen.hpp
 ** Input: none
 ** Output: none
 *********************************************************************/

#include "BlueMen.hpp"
using namespace std;

/**********************************************************************
 ** Function: Default constructor -- BlueMen()
 ** Description: Sets attSides, attcount, defSides, defCount, armor, 
 **   and strength to their appropriate values
 ** Parameters: None
 ** Pre-Conditions: Creature class must exist, include above mentioned
 **   int variables, and have a constructor that accepts all 6 ints
 **   as parameters
 ** Post-Conditions: None
 *********************************************************************/
BlueMen::BlueMen()
: Creature(10, 2, 6, 3, 3, 12) { }

/**********************************************************************
 ** Function: attack()
 ** Description: Sets the BlueMen's attack strength for the turn
 ** Parameters: None
 ** Pre-Conditions: attCount and attSides contain values, att declared
 ** Post-Conditions: None
 *********************************************************************/
void BlueMen::attack() {
  /*Initialize this turn's attack to 0*/   
  att = 0;

  /*Loop through each attack die*/   
  for(int i = 0; i < attCount; i++) {
    /*Initialize seed based on current time, call srand() on seed*/ 
    unsigned seed = time(0);
    srand(seed);

    /*"Roll" the die of given number of sides, add result to def*/  
    att += rand() % attSides + 1;

    /*Wait .5 seconds to ensure next roll is random*/  
    usleep(500000);
  }
}

/**********************************************************************
 ** Function: defend()
 ** Description: Sets the BlueMen's defense for the turn, calculates
 **   and applies damage, based on enemyAtt, def, and armor, decreases
 **   defCount, based on remaining strength
 ** Parameters: Int representing the strength of the enemy's attack
 ** Pre-Conditions: defCount and defSides contain values, def declared
 ** Post-Conditions: None
 *********************************************************************/
void BlueMen::defend(int enemyAtt) {
  /*Initialize int damage by subtracting armor from enemyAtt*/   
  int damage = enemyAtt - armor;

  /*Initialize this turn's defense to 0*/ 
  def = 0;

  /*Loop through each defense die*/ 
  for(int i = 0; i < defCount; i++) {
    /*Initialize seed based on current time, call srand() on seed*/
    unsigned seed = time(0);
    srand(seed);

    /*"Roll" the die of given number of sides, add result to def*/  
    def += rand() % defSides + 1;

    /*Wait .5 seconds to ensure next roll is random*/  
    usleep(500000);
  }

  /*Subtract def from damage*/ 
  damage -= def;

  /*Subtract damage from strength, ignoring negative damage*/  
  if(damage >= 0) {
    strength -= damage;
  }

  /*Decrease defCount to 1 when strength falls to 4 or below*/
  if(strength <= 4) {
    defCount = 1;
  }
  /*Decrease defCount to 2 when strength falls to 8 or below*/
  else if(strength <= 8) {
    defCount = 2;
  }

  /*Print the defCount as representation of mob-members left*/
  cout << defCount << " men left in the mob!" << endl;
}
