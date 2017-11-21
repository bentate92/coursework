
/**********************************************************************
 ** Program Filename: Passenger.hpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Declaration of the Passenger class, which will act as a
 **   space type on the Train
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef PASSENGER_HPP
#define PASSENGER_HPP

#include "Car.hpp"
using namespace std;

/*
 * Creation of Passenger class
 * See Passenger.cpp for full descriptions of functions and data members.
 */
class Passenger : public Car {
  public:
    Passenger(string);
    virtual string inspect(string);
    virtual void use(string);
};

#endif
