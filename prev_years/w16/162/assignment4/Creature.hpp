
/**********************************************************************
 ** Program Filename: Creature.hpp
 ** Author: Benjamin Tate
 ** Date: 2/28/16
 ** Description: Declaration of the Creature base class, which 
 **   contains many data members and functions that characters will use
 **   polymorphism to manage 5 derived classes
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <string>

using namespace std;

/*
 * Creation of Creature class
 * See Creature.cpp for full descriptions of functions and data members.
 * (New members since assignment 3 are marked with // at end of line)
 */
class Creature {
  private:

  protected:
    int id;               //
    string creatureName;  //

    int attSides;
    int attCount;
    int att;
    
    int defSides;
    int defCount;
    int def;
    int armor;
    
    int strength;

    int score;            //

    int startingStr;      //
    int totalDamage;      //

  public:
    Creature(int, int, int, int, int, int);

    int getId();          //
    string getName();     //

    /*Pure virtual attack function, to be used by game characters*/
    virtual void attack() = 0;
    /*Pure virtual defend function, to be used by game characters*/
    virtual void defend(int) = 0;

    int getAtt();
    int getDef();
    int getStr();

    int getScore();       //

    void victory();       //
};

#endif
