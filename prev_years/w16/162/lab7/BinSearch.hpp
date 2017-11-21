
/**********************************************************************
 ** Program Filename: BinSearch.hpp
 ** Author: Benjamin Tate
 ** Date: 2/21/16
 ** Description: Declaration of the BinSearch class, which will perform
 **   a binary search for the a number in the file created by Sorter
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef BINSEARCH_HPP
#define BINSEARCH_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*
 * Creation of BinSearch class
 * See BinSearch.cpp for full descriptions of functions and data members.
 */
class BinSearch {
  private:
    int lineVal;
    int first;      //First element of search
    int last;       //Last element of search
    int middle;     //Midpoint of search
    int position; 
    bool found;
    vector<int> binSearch;  
  
  public:
    BinSearch(string, int);
    int binarySearch(vector<int>&, int, int);
};

#endif
