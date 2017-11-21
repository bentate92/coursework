
/**********************************************************************
 ** Program Filename: Baggage.hpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Declaration of the Baggage class, which will act as a
 **   space type on the Train
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef BAGGAGE_HPP
#define BAGGAGE_HPP

#include "Car.hpp"

/*
 * Creation of Baggage class
 * See Baggage.cpp for full descriptions of functions and data members.
 */
class Baggage : public Car {
  public:
    Baggage(string);
    virtual string inspect(string);
    virtual void use(string);
};

#endif
