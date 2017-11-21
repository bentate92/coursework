
/**********************************************************************
 ** Program Filename: Stack.hpp
 ** Author: Benjamin Tate
 ** Date: 3/6/16
 ** Description: Declaration of the Stack class, which will use the STL
 **   stack container to create a palindrome from a user's string
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
 * Creation of Stack class
 * See Stack.cpp for full descriptions of functions and data members.
 */
class Stack {
  private:
    stack<char> s;

    string startStr;
    string palindrome;

  public:
    Stack();
    void makePal(string);
};

#endif
