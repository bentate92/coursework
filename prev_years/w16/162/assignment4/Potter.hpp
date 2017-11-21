
/**********************************************************************
 ** Program Filename: Potter.hpp
 ** Author: Benjamin Tate
 ** Date: 2/28/16
 ** Description: Declaration of the Potter class, which represents
 **   one character type in the game
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef POTTER_HPP
#define POTTER_HPP

#include "Creature.hpp"

using namespace std;

/*
 * Creation of Potter class, derived from the Creature Class
 * See Potter.cpp for full descriptions of functions and data members.
 * (New members since assignment 3 are marked with // at end of line)
 */
class Potter : public Creature {
  private:
    int hogwarts;

  public:
    Potter(); 
    Potter(string);             // 
   
    virtual void attack();
    virtual void defend(int);
};

#endif
