/*********************************************************************
 ** Program Filename: Life.hpp
 ** Author: Benjamin Tate
 ** Date: 1/17/16
 ** Description: Declaration of Life class, containing, which will
 ** simulate Conway's Game of Life with one of three starting patterns.
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef LIFE_HPP
#define LIFE_HPP

#include<string>

using namespace std;

/* Initiation of enum Pattern to represent the three pattern options*/
enum Pattern {OSCILLATOR, GLIDER, GUN};

/*
 * Implementation of Life class
 * (see Life.cpp for full descriptions of functions and data members
 */
class Life {
  private:
    int mainArray[30][76];
    int neighborCount[30][76];

    Pattern userChoice;

    int windowRow;
    int windowCol;
    int startRow;
    int startCol;

  public:
    Life(string, int, int);
    void buildStart(int[30][76], Pattern, int, int);
    void nextGen();
    void setNeighbors(int[30][76]);
    void copy(int[30][76], int[][76]);
    int getCellVal(int, int);
};

#endif
