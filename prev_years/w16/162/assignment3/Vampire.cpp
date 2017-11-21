
/**********************************************************************
 ** Program Filename: Vampire.cpp
 ** Author: Benjamin Tate
 ** Date: 2/14/16
 ** Description: Implementation of the Vampire class, described in
 **   Vampire.hpp
 ** Input: none
 ** Output: none
 *********************************************************************/

#include "Vampire.hpp"
using namespace std;

/**********************************************************************
 ** Function: Default constructor -- Vampire()
 ** Description: Sets attSides, attcount, defSides, defCount, armor, 
 **   and strength to their appropriate values
 ** Parameters: None
 ** Pre-Conditions: Creature class must exist, include above mentioned
 **   int variables, and have a constructor that accepts all 6 ints
 **   as parameters
 ** Post-Conditions: None
 *********************************************************************/
Vampire::Vampire()
: Creature(12, 1, 6, 1, 1, 18) { }

/**********************************************************************
 ** Function: attack()
 ** Description: Sets the Vampire's attack strength for the turn
 ** Parameters: None
 ** Pre-Conditions: attCount and attSides contain values, att declared
 ** Post-Conditions: None
 *********************************************************************/
void Vampire::attack() {
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
 ** Description: Sets the Vampire's defense for the turn, calculates
 **   and applies damage, based on enemyAtt, def, and armor, has 50%
 **   chance to ignore enemy's attack each turn
 ** Parameters: Int representing the strength of the enemy's attack
 ** Pre-Conditions: defCount and defSides contain values, def declared
 ** Post-Conditions: None
 *********************************************************************/
void Vampire::defend(int enemyAtt) {
  /*Initialize this turn's defense to 0*/ 
  def = 0;

  /*Initialize seed based on current time, call srand() on seed*/ 
  unsigned seed = time(0);
  srand(seed);

  /*Randomly assign charm a value of either 0 or 1*/
  charm = rand() % 2;

  /*If charm is 0, carry out defense as usual*/
  if(charm == 0) {
    /*Initialize int damage by subtracting armor from enemyAtt*/ 
    int damage = enemyAtt - armor;
  
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
  }
  /*If charm is 1, ignore opponent's attack and print why*/
  else {
    cout << "Vampire used Charm!" << endl;
  }
}
