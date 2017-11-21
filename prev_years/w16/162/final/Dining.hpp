
/**********************************************************************
 ** Program Filename: Dining.hpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Declaration of the Dining class, which will act as a
 **   space type on the Train
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef DINING_HPP
#define DINING_HPP

#include "Car.hpp"

/*
 * Creation of Dining class
 * See Dining.cpp for full descriptions of functions and data members.
 */
class Dining : public Car {
  public:
    Dining(string);
    virtual string inspect(string);
    virtual void use(string);
};

#endif
