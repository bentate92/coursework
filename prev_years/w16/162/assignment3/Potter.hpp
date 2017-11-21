
/**********************************************************************
 ** Program Filename: Potter.hpp
 ** Author: Benjamin Tate
 ** Date: 2/14/16
 ** Description: Declaration of the Potter class, which represents
 **   one character type in the game
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef POTTER_HPP
#define POTTER_HPP

#include "Creature.hpp"

/*
 * Creation of Potter class, derived from the Creature Class
 * See Potter.cpp for full descriptions of functions and data members.
 */
class Potter : public Creature {
  private:
    int hogwarts;

  public:
    Potter(); 
   
    virtual void attack();
    virtual void defend(int);
};

#endif
