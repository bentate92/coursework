
/**********************************************************************
 ** Program Filename: Medusa.hpp
 ** Author: Benjamin Tate
 ** Date: 2/28/16
 ** Description: Declaration of the Medusa class, which represents one
 **   character type in the game
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"

using namespace std;

/*
 * Creation of Medusa class, derived from the creature class
 * See Medusa.cpp for full descriptions of functions and data members.
 * (New members since assignment 3 are marked with // at end of line)
 */
class Medusa : public Creature {
  public:
    Medusa();
    Medusa(string);             //

    virtual void attack();
    virtual void defend(int);
};

#endif
