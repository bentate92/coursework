
/**********************************************************************
 ** Program Filename: Barbarian.hpp
 ** Author: Benjamin Tate
 ** Date: 2/14/16
 ** Description: Declaration of the Barbarian class, which represents
 **   one character type in the game
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"

/*
 * Creation of Barbarian class, derived from the Creature Class
 * See Barbarian.cpp for full descriptions of functions and data members.
 */
class Barbarian : public Creature {
  public:
    Barbarian(); 
   
    virtual void attack();
    virtual void defend(int);
};

#endif
