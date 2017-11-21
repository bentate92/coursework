
/**********************************************************************
 ** Program Filename: Tournament.hpp
 ** Author: Benjamin Tate
 ** Date: 2/28/16
 ** Description: Declaration of the Tournament class, which will manage
 **   two players' teams as they battle
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP

#include "Tournament.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "Potter.hpp"
#include "BlueMen.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include <string>
using namespace std;

/*
 * Creation of Tournament class
 * See Tournament.cpp for full descriptions of functions and data members.
 */
class Tournament {
  private:
    int battleCount;
    Queue t1;
    Queue t2;

    Stack losers;

  public:
    Tournament(Queue, Queue);
    void battle();
    void results();

    Queue getT1();
    Queue getT2();
};

#endif
