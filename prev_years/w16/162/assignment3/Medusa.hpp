
/**********************************************************************
 ** Program Filename: Medusa.hpp
 ** Author: Benjamin Tate
 ** Date: 2/14/16
 ** Description: Declaration of the Medusa class, which represents one
 **   character type in the game
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"

/*
 * Creation of Medusa class, derived from the creature class
 * See Medusa.cpp for full descriptions of functions and data members.
 */
class Medusa : public Creature {
  public:
    Medusa();

    virtual void attack();
    virtual void defend(int);
};

#endif
