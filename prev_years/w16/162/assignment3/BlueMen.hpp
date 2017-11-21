
/**********************************************************************
 ** Program Filename: BlueMen.hpp
 ** Author: Benjamin Tate
 ** Date: 2/14/16
 ** Description: Declaration of the BlueMen class, which represents
 **   one character type in the game
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Creature.hpp"

/*
 * Creation of BlueMen class, derived from the Creature Class
 * See BlueMen.cpp for full descriptions of functions and data members.
 */
class BlueMen : public Creature {
  public:
    BlueMen(); 
   
    virtual void attack();
    virtual void defend(int);
};

#endif
