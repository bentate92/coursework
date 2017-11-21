
/**********************************************************************
 ** Program Filename: Bathroom.hpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Declaration of the Bathroom class, which will act as a
 **   space type on the Train
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef BATHROOM_HPP
#define BATHROOM_HPP

#include "Car.hpp"

/*
 * Creation of Bathroom class
 * See Bathroom.cpp for full descriptions of functions and data members.
 */
class Bathroom : public Car {
  public:
    Bathroom(string);
    virtual string inspect(string);
    virtual void use(string);
};

#endif
