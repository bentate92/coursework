
/**********************************************************************
 ** Program Filename: LinSearch.cpp
 ** Author: Benjamin Tate
 ** Date: 2/21/16
 ** Description: Implementation of the LinSearch class, described in
 **   LinSearch.hpp
 ** Citation: Algorithm adapted from example on pages 596-597 of book
 ** Input: Information from search1.txt, search2.txt, search3.txt, and
 **   search4.txt
 ** Output: Results of searches
 *********************************************************************/

#include "LinSearch.hpp"

using namespace std;

/**********************************************************************
 ** Function: Default constructor -- LinSearch()
 ** Description: Creates vectors from each of the four .txt files, 
 **   calls searchList on each, and prints the results of each search
 ** Parameters: None
 ** Pre-Conditions: Four files with appropriate names must exist
 ** Post-Conditions: None
 *********************************************************************/
LinSearch::LinSearch() {
  /*Open search1.txt*/
  ifstream search1("search1.txt", ios::in);

  /*Insert int on each line of file into searchArr1 vector*/
  while(search1 >> lineVal) {
    searchArr1.push_back(lineVal);
  }

  /*Close search1.txt*/
  search1.close();

  /*Open search2.txt*/
  ifstream search2("search2.txt", ios::in);

  /*Insert int on each line of file into searchArr2 vector*/
  while(search2 >> lineVal) {
    searchArr2.push_back(lineVal);
  }

  /*Close search2.txt*/
  search2.close();

  /*Open search3.txt*/
  ifstream search3("search3.txt", ios::in);

  /*Insert int on each line of file into searchArr3 vector*/
  while(search3 >> lineVal) {
    searchArr3.push_back(lineVal);
  }

  /*Close search3.txt*/
  search3.close();

  /*Open search4.txt*/
  ifstream search4("search4.txt", ios::in);

  /*Insert int on each line of file into searchArr4 vector*/
  while(search4 >> lineVal) {
    searchArr4.push_back(lineVal);
  }

  /*Close search4.txt*/
  search4.close();

  /*Print the location of the 0 in search1.txt, if any exists*/
  cout << "In search1.txt:" << endl;
  /*Call searchList on searchArr1*/
  if(searchList(searchArr1, 20) == -1) {
    cout << "No zero found!\n" << endl;
  }
  else {
    cout << "Zero found on line " << searchList(searchArr1, 20) + 1
         << "!\n" << endl;
  }

  /*Print the location of the 0 in search2.txt, if any exists*/
  cout << "In search2.txt:" << endl;
  /*Call searchList on searchArr2*/
  if(searchList(searchArr2, 21) == -1) {
    cout << "No zero found!\n" << endl;
  }
  else {
    cout << "Zero found on line " << searchList(searchArr2, 21) + 1
         << "!\n" << endl;
  }

  /*Print the location of the 0 in search3.txt, if any exists*/
  cout << "In search3.txt:" << endl;
  /*Call searchList on searchArr3*/
  if(searchList(searchArr3, 21) == -1) {
    cout << "No zero found!\n" << endl;
  }
  else {
    cout << "Zero found on line " << searchList(searchArr3, 21) + 1 
         << "!\n" << endl;
  }

  /*Print the location of the 0 in search4.txt, if any exists*/
  cout << "In search4.txt:" << endl;
  /*Call searchList on searchArr4*/
  if(searchList(searchArr4, 21) == -1) {
    cout << "No zero found!\n" << endl;
  }
  else {
    cout << "Zero found on line " << searchList(searchArr4, 21) + 1
         << "!\n" << endl;
  }
}

/**********************************************************************
 ** Function: searchList()
 ** Description: Searches a vector of a given size for a 0, returns  
 **   location of 0 if any exists, and -1 otherwise
 ** Parameters: Vector of ints to be searched, int size of vector
 ** Pre-Conditions: Input vector must be populated with ints, size must
 **   be accurate
 ** Post-Conditions: None
 *********************************************************************/
int LinSearch::searchList(vector<int>& search, int size) {
  /*Initialize index to 0*/
  index = 0;
  /*Initialize position to -1 to represent that no 0 exists in vector*/
  position = -1;
  /*Initialize found to false*/
  found = false;

  /*Repeat until 0 has been found or end of vector has been reached*/
  while(index < size && !found) {
    /*If vector at current index is 0, update position to index*/
    if(search[index] == 0) {
      /*Adjust found to true to stop while loop*/
      found = true;
      position = index;
    }

    /*Increment index*/
    index++;
  }
    
  return position;
}

