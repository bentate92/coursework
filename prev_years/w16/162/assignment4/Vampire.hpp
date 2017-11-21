
/**********************************************************************
 ** Program Filename: Vampire.hpp
 ** Author: Benjamin Tate
 ** Date: 2/28/16
 ** Description: Declaration of the Vampire class, which represents
 **   one character type in the game
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Creature.hpp"

using namespace std;

/*
 * Creation of Vampire class, derived from the Creature class
 * See Vampire.cpp for full descriptions of functions and data members.
 * (New members since assignment 3 are marked with // at end of line)
 */
class Vampire : public Creature {
  private:
    int charm;

  public:
    Vampire(); 
    Vampire(string);            //
   
    virtual void attack();
    virtual void defend(int);
};

#endif
