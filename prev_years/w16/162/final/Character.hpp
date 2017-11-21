
/**********************************************************************
 ** Program Filename: Character.hpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Declaration of the Character class, which will manage
 **   the game
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Train.hpp"
using namespace std;

/*
 * Creation of Character class
 * See Character.cpp for full descriptions of functions and data members.
 */
class Character {
  private:
    int movesLeft;

    string action;
    string item;
    string inspection;
    string movement;

    int keyCount;
    int whiskeyCount;
    vector<string> inventory;

    vector<string> spaces;

  public:
    Character();
    void game(Train*);
    void move(Train*);
    void buildSpaces(Train*);
    void checkInv(Train*);
    void use(Train*);
    void inspect(Train*);
};

#endif
