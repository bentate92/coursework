
/**********************************************************************
 ** Program Filename: BinSearch.cpp
 ** Author: Benjamin Tate
 ** Date: 2/21/16
 ** Description: Implementation of the BinSearch class, described in
 **   BinSearch.hpp
 ** Citation: Algorithm adapted from example on pages 600-601 of book
 ** Input: Name of file created by Sorter, value to search for
 ** Output: Results of search
 *********************************************************************/

#include "BinSearch.hpp"

using namespace std;

/**********************************************************************
 ** Function: Constructor -- BinSearch()
 ** Description: Creates vector from .txt file created by Sorter, 
 **   calls binarySearch on it, and prints the results of the search
 ** Parameters: String representing the name of the file being searched,
 **   int representing the value being searched for
 ** Pre-Conditions: Sorted file must exist, and name must not have 
 **   been changed since creation, val must be selected
 ** Post-Conditions: None
 *********************************************************************/
BinSearch::BinSearch(string outputName, int val) {
  /*Open sorted file*/  
  ifstream searchfile(outputName.c_str(), ios::in);

 /*Insert int on each line of sorted file into binSearch vector*/
  while(searchfile >> lineVal) {
    binSearch.push_back(lineVal);
  }

  /*Close sorted file*/
  searchfile.close();

  /*Inform user that binary search is beginning*/
  cout << "\nPerforming binary search on sorted list..." << endl;
  
  /*
   * Call binarySearch on binSearch with given value, print a position
   * of the value, if any exists
   */
  if(binarySearch(binSearch, 21, val) == -1) {
    cout << "Unable to find sepecified value." << endl;
  }
  else {
    cout << "Found specified value on line " 
         << binarySearch(binSearch, 21, val) + 1 << endl;
  }
}

/**********************************************************************
 ** Function: binarySearch()
 ** Description: Searches a vector of a given size for a given value,   
 **   returns a location of value if any exists, and -1 otherwise
 ** Parameters: Vector of ints to be searched, int size of vector, int
 **   value to be searched for
 ** Pre-Conditions: Input vector must be populated with ints, size must
 **   be accurate, value must be chosen
 ** Post-Conditions: None
 *********************************************************************/
int BinSearch::binarySearch(vector<int>& sorted, int size, int value) {
  /*Initialize first to 0*/
  first = 0;
  /*Initialize last to size - 1*/
  last = size - 1;
  /*Initialize position to -1 to represent that no 0 exists in vector*/
  position = -1;
  /*Initialize found to false*/ 
  found = false;

  /*Repeat until value has been found or entire list has been searched*/
  while(!found && first <= last) {
    /*Calculate midpoint*/
    middle = (first + last) / 2;
    
    /*If value exists at middle, set found to true, update position*/
    if(sorted[middle] == value) {
      found = true;
      position = middle;
    }
    /*If middle element is larger than value, value is in lower half*/
    else if(sorted[middle] > value) {
      last = middle - 1;
    }
    /*If middle element is smaller than value, value is in upper half*/
    else {
      first = middle + 1;
    }
  }

  return position;
}
