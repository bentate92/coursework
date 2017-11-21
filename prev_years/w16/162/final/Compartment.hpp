
/**********************************************************************
 ** Program Filename: Compartment.hpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Declaration of the Compartment class, which will act as
 **   a space type on the Train
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef COMPARTMENT_HPP
#define COMPARTMENT_HPP

#include "Car.hpp"

/*
 * Creation of Compartment class
 * See Compartment.cpp for full descriptions of functions and data members.
 */
class Compartment : public Car {
  public:
    Compartment(string);
    virtual string inspect(string);
    virtual void use(string);
};

#endif
