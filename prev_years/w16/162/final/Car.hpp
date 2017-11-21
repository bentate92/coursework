
/**********************************************************************
 ** Program Filename: Car.hpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Declaration of the Car class, which will be the base
 **   space type on the Train
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef CAR_HPP 
#define CAR_HPP

#include <iostream> 
#include <string>
#include <vector>
using namespace std;

/*
 * Creation of Car class
 * See Car.cpp for full descriptions of functions and data members.
 */
class Car {
  protected:
    int checkCount;
    string entrance;
    string newEntrance;

    string carName;

    bool extraCondition;
    string inspection;
    string item;

  public:
    Car();
    string getName();
    void enter();
    bool getExtra();
    void changeExtra();
    virtual string inspect(string) = 0;
    virtual void use(string) = 0;
};

#endif 
    
