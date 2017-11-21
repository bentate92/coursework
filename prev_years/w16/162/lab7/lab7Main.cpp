
/**********************************************************************
 ** Program Filename: lab7Main.cpp
 ** Author: Benjamin Tate
 ** Date: 2/21/16
 ** Description: Provides some user prompts and creates necessary
 **   objects
 ** Input: Name of file to store sorted list in, value to search for
 **   using BinSearch
 ** Output: Prompts
 *********************************************************************/

#include "LinSearch.hpp"
#include "Sorter.hpp"
#include "BinSearch.hpp"

using namespace std;

int main() {
  /*Initialize string to hold sorted file name*/
  string outputName;
  /*Initialize int to hold value to search for*/
  int val;

  /*Create LinSearch object*/
  LinSearch search1;

  /*Prompt user for name of file to store sorted list in, accept input*/
  cout << "What would you like to call the file that will hold the "
       << "sorted list?" << endl;
  cin >> outputName;

  /*Create Sorter object*/
  Sorter sort(outputName);

  /*Prompt user for integer to search sorted list for, accept input*/
  cout << "What integer (0-9) would you like to search the new file for?" 
       << endl;
  cin >> val;

  /*Create BinSearch object*/
  BinSearch search2(outputName, val);

  return 0;
}
