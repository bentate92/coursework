
/**********************************************************************
 ** Program Filename: Train.hpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Declaration of the Train class, which will act as the
 **   shape of the "game board"
 ** Input: None
 ** Output: None
 *********************************************************************/

#ifndef TRAIN_HPP
#define TRAIN_HPP

#include "Engine.hpp"
#include "Compartment.hpp"
#include "Passenger.hpp"
#include "Bathroom.hpp"
#include "Dining.hpp"
#include "BtwCars.hpp"
#include "Train.hpp"
#include "Baggage.hpp"
#include "Top.hpp"
using namespace std;

/*
 * Creation of Train class
 * See Train.cpp for full descriptions of functions and data members.
 */
class Train {
  private:
    struct TrainNode {
      int ptrs;

      Car* nodeCar;
      TrainNode* next;
      TrainNode* prev;
      TrainNode* updwn;
      TrainNode* spec1;
      TrainNode* spec2;

      TrainNode(Car* car1) {
        nodeCar = car1;

        int ptrs = 0;
      }
    };

    bool ending;

    TrainNode* charCar;
    TrainNode* build;
    TrainNode* front;
    TrainNode* back;

  public:
    Train(Car*, Car*, Car*, Car*, Car*, Car*, Car*, Car*, Car*, Car*, Car*, Car*, Car*, Car*, Car*, Car*);
    Car* getCar(TrainNode*);
    vector<string> getSpaces();
    void moveChar(string);
    void use(string);
    void inspect(string);
    bool getEngine();
    bool getBtw();
    bool getEnd();
};

#endif
