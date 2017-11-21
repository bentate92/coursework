
/**********************************************************************
 ** Program Filename: BtwCars.hpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Declaration of the BtwCars class, which will act as a
 **   space type on the Train
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef BTWCARS_HPP
#define BTWCARS_HPP

#include "Car.hpp"

/*
 * Creation of BtwCars class
 * See BtwCars.cpp for full descriptions of functions and data members.
 */
class BtwCars : public Car {
  public:
    BtwCars(string);
    virtual string inspect(string);
    virtual void use(string);
};

#endif
