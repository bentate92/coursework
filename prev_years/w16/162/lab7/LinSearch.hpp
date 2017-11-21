
/**********************************************************************
 ** Program Filename: LinSearch.hpp
 ** Author: Benjamin Tate
 ** Date: 2/21/16
 ** Description: Declaration of the LinSearch class, which will perform
 **   a linear search for the number 0 in four .txt files
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef LINSEARCH_HPP
#define LINSEARCH_HPP

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*
 * Creation of LinSearch class
 * See LinSearch.cpp for full descriptions of functions and data members.
 */
class LinSearch {
  private:
    int lineVal;
    int index;
    int position;
    bool found;

    vector<int> searchArr1;  
    vector<int> searchArr2;
    vector<int> searchArr3;
    vector<int> searchArr4;
  
  public:
    LinSearch();
    int searchList(vector<int>&, int);
};

#endif
