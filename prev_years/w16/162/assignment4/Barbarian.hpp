
/**********************************************************************
 ** Program Filename: Barbarian.hpp
 ** Author: Benjamin Tate
 ** Date: 2/28/16
 ** Description: Declaration of the Barbarian class, which represents
 **   one character type in the game
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"
using namespace std;

/*
 * Creation of Barbarian class, derived from the Creature Class
 * See Barbarian.cpp for full descriptions of functions and data members.
 * (New members since assignment 3 are marked with // at end of line)
 */
class Barbarian : public Creature {
  public:
    Barbarian();
    Barbarian(string);          //
   
    virtual void attack();
    virtual void defend(int);
};

#endif
