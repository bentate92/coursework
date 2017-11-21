
/**********************************************************************
 ** Program Filename: Sorter.cpp
 ** Author: Benjamin Tate
 ** Date: 2/21/16
 ** Description: Implementation of the Sorter class, described in
 **   Sorter.hpp
 ** Citation: Algorithm adapted from example on pages 608-609 of book
 ** Input: Name of file to store output in
 ** Output: File with sorted list, progress feedback statements
 *********************************************************************/

#include "Sorter.hpp"

using namespace std;

/**********************************************************************
 ** Function: Constructor -- Sorter()
 ** Description: Creates vector from one of the .txt files, calls  
 **   sortArray, and prints sorted list to new file named by user
 ** Parameters: String representing the user's choice of file name
 ** Pre-Conditions: File name must be selected, search2.txt must exist
 ** Post-Conditions: None
 *********************************************************************/
Sorter::Sorter(string outputName) {
  /*Open search2.txt*/
  ifstream sortfile("search2.txt", ios::in);

  /*Insert int on each line of file into searchArr2 vector*/ 
  while(sortfile >> lineVal) {
    sorted.push_back(lineVal);
  }

  /*Close search2.txt*/  
  sortfile.close();

  /*Call sortArray on sorted*/
  sortArray(sorted, 21);

  /*Open new file with with user-selected name*/
  ofstream sortedfile(outputName.c_str());

  /*Print contents of sorted vector to new file*/
  for(int i = 0; i < 21; i++) {
    sortedfile << sorted[i] << endl;
  }

  /*Close new file*/
  sortedfile.close();

  /*Inform user that the operation was successful*/
  cout << "List (including zero) sorted!\n" << endl;
} 

/**********************************************************************
 ** Function: sortArray()
 ** Description: Sorts a vector of given size in ascending order  
 ** Parameters: Vector of ints to be sorted, int size of vector
 ** Pre-Conditions: Input vector must be populated with ints, size must
 **   be accurate
 ** Post-Conditions: None
 *********************************************************************/
void Sorter::sortArray(vector<int>& sort, int size) {
  /*Initialize temp int to hold values*/
  int temp;
  /*
   * Initialize swap bool, which will be true if two numbers were 
   * swapped
   */
  bool swap;

  /*Repeat as long as swap is true, perform at least once*/
  do {
    /*Set swap to false*/
    swap = false;
    
    /*Iterate through vector, up to second to last element*/
    for(int i = 0; i< size - 1; i++) {
      /*Check if current element is larger than the next element*/
      if(sort[i] > sort[i + 1]) {
        /*Set temp to current element*/
        temp = sort[i];
        /*Set current element to next element*/
        sort[i] = sort[i + 1];
        /*Set next element to temp*/
        sort[i + 1] = temp;
        /*Set swap to true*/
        swap = true;
      }
    }
  } while(swap);
} 
