
/**********************************************************************
 ** Program Filename: Stack.cpp
 ** Author: Benjamin Tate
 ** Date: 3/6/16
 ** Description: Implementation of the Stack class, described in
 **   Stack.hpp
 ** Input: Responses to prompts
 ** Output: Various prompts
 *********************************************************************/

#include "Stack.hpp"
using namespace std;

/**********************************************************************
 ** Function: Default constructor -- Stack()
 ** Description: Provides prompts for user input, calls makePal(), and 
 **   prints the created palindrome
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
Stack::Stack() {
  /*Prompt user for string and store in startStr*/
  cout << "\nEnter a string, and I'll return a palindrome!"
       << "\nWhat is your string?" << endl;
  cin >> startStr;
  /*Initialize palindrome as the same as startStr*/
  palindrome = startStr;

  /*Call makePal() on startStr*/
  makePal(startStr);

  /*Print the palindrome*/
  cout << "\nHere is the palindrome: "
       << "\n" << palindrome << endl;
}

/**********************************************************************
 ** Function: makePal()
 ** Description: Creates a palindrome from input string
 ** Parameters: String to turn into palindrome
 ** Pre-Conditions: original must contain a valid string
 ** Post-Conditions: None
 *********************************************************************/
void Stack::makePal(string original) {
  /*Continue for entire length of original string*/
  for(int i = 0; i < original.length(); i++) {
    /*Add original string to stack, char by char*/
    s.push(original.at(i));
  }

  /*Continue as long as the stack contains chars*/
  while(!s.empty()) {
    /*Add top value of stack to end of palindrome*/
    palindrome.push_back(s.top());
    /*Remove top value of stack*/
    s.pop();
  }
}

  
