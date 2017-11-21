
/**********************************************************************
 ** Program Filename: Sorter.hpp
 ** Author: Benjamin Tate
 ** Date: 2/21/16
 ** Description: Declaration of the Sorter class, which will sort one
 **   of four .txt files in ascending order into a new file, whose name
 **   will be specified by the user
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef SORTER_HPP
#define SORTER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
 * Creation of Sorter class
 * See Sorter.cpp for full descriptions of functions and data members.
 */
class Sorter {
  private:
    int lineVal;
    string outputName;
    vector<int> sorted;

  public:
    Sorter(string);
    void sortArray(vector<int>&, int size);
};

#endif
