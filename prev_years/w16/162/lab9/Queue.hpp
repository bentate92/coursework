
/**********************************************************************
 ** Program Filename: Queue.hpp
 ** Author: Benjamin Tate
 ** Date: 3/6/16
 ** Description: Declaration of the Queue class, which will use the STL
 **   queue container to simulate a server taking jobs
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
using namespace std;

/*
 * Creation of Queue class
 * See Queue.cpp for full descriptions of functions and data members.
 */
class Queue {
  private:
    queue<int> q;

    int turns;
    int addChance;
    int remChance;

    int addIt;
    int remIt;
    int val;

    int sum;
    double avg;

  public:
    Queue();
    void randInt(int, int);
};

#endif
