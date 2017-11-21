
/**********************************************************************
 ** Program Filename: Train.cpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Implementation of the Train class, described in
 **   Train.hpp
 ** Input: None
 ** Output: None
 *********************************************************************/

#include "Train.hpp"
using namespace std;

/**********************************************************************
 ** Function: Constructor -- Train()
 ** Description: Sets ending to false, builds the linked list of
 **   TrainNodes
 ** Parameters: 10 pointers to Cars, which represent the 10 spaces
 ** Pre-Conditions: 10 Car objects must exist and be in proper order
 ** Post-Conditions: None
 *********************************************************************/
Train::Train(Car* engine, Car* compartment, Car* pass1, Car* bath1, 
             Car* dining, Car* pass2, Car* bath2, Car* guard, Car* between, 
             Car* baggage, Car* engineTop, Car* pass1Top, Car* diningTop, 
             Car* pass2Top, Car* guardTop, Car* baggageTop) {
  /*Set ending to false*/
  ending = false;

  /*Build engine pointers*/
  build = new TrainNode(engine);
  build->updwn = new TrainNode(engineTop);
  build->ptrs += 1;
  build->next = new TrainNode(pass1);
  build->ptrs += 1;
  build->spec1 = new TrainNode(compartment);
  build->ptrs += 1;
  front = build;
  build->updwn->updwn = build;
  build->updwn->ptrs += 1;
  build->next->prev = build;
  build->next->ptrs += 1;
  build->spec1->spec1 = build;
  build->spec1->ptrs += 1;

  /*Build engineTop pointers*/
  build = build->updwn;
  build->next = new TrainNode(pass1Top);
  build->ptrs += 1;
  build->spec1 = build->updwn->next;
  build->ptrs += 1;
  build->next->prev = build;
  build->next->ptrs += 1;

  /*Build pass1Top pointers*/
  build = build->next;
  build->next = new TrainNode(diningTop);
  build->ptrs += 1;
  build->updwn = build->prev->spec1;
  build->ptrs += 1;
  build->spec1 = new TrainNode(dining);
  build->ptrs += 1;
  build->spec2 = build->prev->updwn;
  build->ptrs += 1;
  build->updwn->updwn = build;
  build->updwn->ptrs += 1;
  build->next->prev = build;
  build->next->ptrs += 1;

  /*Build pass1 pointers*/
  build = build->updwn;
  charCar = build;     //Set character sentinel
  build->next = build->updwn->spec1;
  build->ptrs += 1;
  build->spec1 = new TrainNode(bath1);
  build->ptrs += 1;
  build->spec1->spec1 = build;
  build->spec1->ptrs += 1;
  build->next->prev = build;
  build->next->ptrs += 1;

  /*Build dining pointers*/
  build = build->next;
  build->next = new TrainNode(pass2);
  build->ptrs += 1;
  build->updwn = build->prev->updwn->next;
  build->ptrs += 1;
  build->updwn->updwn = build;
  build->updwn->ptrs += 1;
  build->next->prev = build;
  build->next->ptrs += 1;

  /*Build diningTop pointers*/
  build = build->updwn;
  build->next = new TrainNode(pass2Top);
  build->ptrs += 1;
  build->spec1 = build->updwn->next;
  build->ptrs += 1;
  build->spec2 = build->updwn->prev;
  build->ptrs += 1;
  build->next->prev = build;
  build->next->ptrs += 1;

  /*Build pass2Top pointers*/
  build = build->next;
  build->next = new TrainNode(guardTop);
  build->ptrs += 1;
  build->updwn = build->prev->spec1;
  build->ptrs += 1;
  build->spec1 = new TrainNode(guard);
  build->ptrs += 1;
  build->spec2 = build->prev->updwn;
  build->ptrs += 1;
  build->updwn->updwn = build;
  build->updwn->ptrs += 1;
  build->next->prev = build;
  build->next->ptrs += 1;

  /*Build pass2 pointers*/
  build = build->updwn;
  build->next = build->updwn->spec1;
  build->ptrs += 1;
  build->spec1 = new TrainNode(bath2);
  build->ptrs += 1;
  build->next->prev = build;
  build->next->ptrs += 1;
  build->spec1->spec1 = build;
  build->spec1->ptrs += 1;

  /*Build guard pointers*/
  build = build->next;
  build->next = new TrainNode(between);
  build->ptrs += 1;
  build->updwn = build->prev->updwn->next;
  build->ptrs += 1;
  build->updwn->updwn = build;
  build->updwn->ptrs += 1;
  build->next->prev = build;
  build->next->ptrs += 1;

  /*Build between pointers*/
  build = build->next;
  build->next = new TrainNode(baggage);
  build->ptrs += 1;
  back = build->next;
  build->updwn = new TrainNode(baggageTop);
  build->ptrs += 1;
  build->next->prev = build;
  build->next->ptrs += 1;
  build->updwn->updwn = build;
  build->updwn->ptrs += 1;
  
  /*Build guardTop pointers*/
  build = build->prev->updwn;
  build->spec1 = build->updwn->next;
  build->ptrs += 1;
  build->spec2 = build->updwn->prev;
  build->ptrs += 1;
  build->next = build->spec1->updwn;
  build->ptrs += 1;
  build->next->prev = build;
  build->next->ptrs += 1;
  
  /*Build baggageTop pointers*/
  build = build->next;
  build->spec2 = build->prev->updwn;
}

/**********************************************************************
 ** Function: getCar()
 ** Description: Returns a Car* at a particular node
 ** Parameters: TrainNode to return Car* of
 ** Pre-Conditions: temp must exist and not be NULL
 ** Post-Conditions: None
 *********************************************************************/
Car* Train::getCar(TrainNode* temp) {
  Car* thisCar = temp->nodeCar;

  return thisCar;
}

/**********************************************************************
 ** Function: getSpaces()
 ** Description: Vector of strings representing the names of the spaces
 **   surrounding the character
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
vector<string> Train::getSpaces() {
  vector<string> surrounding(5);
  int count = 0;

  if(charCar->next != NULL) {
    if(getCar(charCar)->getName() != "passenger car 3" ||  getCar(charCar)->getExtra()) {
      surrounding[count] = getCar(charCar->next)->getName();
      count++;
    }
  }
  if(charCar->prev != NULL) {
    surrounding[count] = getCar(charCar->prev)->getName();
    count++;
  }
  if(charCar->updwn != NULL) {
    surrounding[count] = getCar(charCar->updwn)->getName();
    count++;
  }
  if(charCar->spec1 != NULL) {
    if(getCar(charCar)->getName() != "engine room" || getCar(charCar)->getExtra()) {
      surrounding[count] = getCar(charCar->spec1)->getName();
      count++;
    }
  }
  if(charCar->spec2 != NULL) {
    surrounding[count] = getCar(charCar->spec2)->getName();
    count++;
  }

  return surrounding;
}

/**********************************************************************
 ** Function: moveChar()
 ** Description: Moves charCar to appropriate space and calls enter()
 **   of that space
 ** Parameters: String of name of space to move to
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
void Train::moveChar(string move) {
  if(charCar->next != NULL && move == getCar(charCar->next)->getName()) {
    charCar = charCar->next;
  
    getCar(charCar)->enter();
  }
  else if(charCar->prev != NULL && move == getCar(charCar->prev)->getName()) {
    charCar = charCar->prev;
  
    getCar(charCar)->enter();
  }
  else if(charCar->updwn != NULL && move == getCar(charCar->updwn)->getName()) {
    charCar = charCar->updwn;

    getCar(charCar)->enter();
  }
  else if(charCar->spec1 != NULL && move == getCar(charCar->spec1)->getName()) {
    charCar = charCar->spec1;

    getCar(charCar)->enter();
  }
  else if(charCar->spec2 != NULL && move == getCar(charCar->spec2)->getName()) {
    charCar = charCar->spec2;

    getCar(charCar)->enter(); 
  }
  else {
    cout << "Can't reach " << move << " right now." << endl;
  }
}

/**********************************************************************
 ** Function: use()
 ** Description: Calls use of current space
 ** Parameters: String of what to use
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
void Train::use(string use) {
  getCar(charCar)->use(use);
}

/**********************************************************************
 ** Function: inspect()
 ** Description: Calls inspect of current space, calls changeExtra() if
 **   necessary
 ** Parameters: String of what to inspect
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
void Train::inspect(string inspect) {
  string inv = getCar(charCar)->inspect(inspect);

  if(inv == "key") {
    getCar(back->prev)->changeExtra();
  }
  if(inv == "whiskey") {
    getCar(front)->changeExtra();
  }
  if(inv == "end") {
    ending = true;
  }
}

/**********************************************************************
 ** Function: getEngine()
 ** Description: Returns true if engine room's extraCondition is met
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
bool Train::getEngine() {
  return getCar(front)->getExtra();
}

/**********************************************************************
 ** Function: getBtw()
 ** Description: Returns true if BtwCars extraCondition is met
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
bool Train::getBtw() {
  return getCar(back->prev)->getExtra();
}

/**********************************************************************
 ** Function: getEnd()
 ** Description: Returns true if ending condition is met
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
bool Train::getEnd() {
  return ending;
}

