
/**********************************************************************
 ** Program Filename: Vampire.hpp
 ** Author: Benjamin Tate
 ** Date: 2/14/16
 ** Description: Declaration of the Vampire class, which represents
 **   one character type in the game
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Creature.hpp"

/*
 * Creation of Vampire class, derived from the Creature class
 * See Vampire.cpp for full descriptions of functions and data members.
 */
class Vampire : public Creature {
  private:
    int charm;

  public:
    Vampire(); 
   
    virtual void attack();
    virtual void defend(int);
};

#endif
