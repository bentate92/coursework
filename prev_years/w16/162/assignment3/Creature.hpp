
/**********************************************************************
 ** Program Filename: Creature.hpp
 ** Author: Benjamin Tate
 ** Date: 2/14/16
 ** Description: Declaration of the Creature base class, which 
 **   contains many data members and functions that characters will use
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

/*
 * Creation of Creature class
 * See Creature.cpp for full descriptions of functions and data members.
 */
class Creature {
  private:

  protected:
    int attSides;
    int attCount;
    int att;
    
    int defSides;
    int defCount;
    int def;

    int armor;
    
    int strength;

  public:
    Creature(int, int, int, int, int, int);
    /*Pure virtual attack function, to be used by game characters*/
    virtual void attack() = 0;
    /*Pure virtual defend function, to be used by game characters*/
    virtual void defend(int) = 0;

    int getAtt();
    int getDef();
    int getStr();
};

#endif
