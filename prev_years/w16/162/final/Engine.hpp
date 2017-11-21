
/**********************************************************************
 ** Program Filename: Engine.hpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Declaration of the Engine class, which will act as a
 **   space type on the Train
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Car.hpp"

/*
 * Creation of Engine class
 * See Engine.cpp for full descriptions of functions and data members.
 */
class Engine : public Car {
  public:
    Engine(string);
    virtual string inspect(string);
    virtual void use(string);
};

#endif
