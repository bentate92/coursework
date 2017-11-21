
/**********************************************************************
 ** Program Filename: Character.cpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Implementation of the Character class, described in
 **   Character.hpp
 ** Input: None
 ** Output: None
 *********************************************************************/

#include "Character.hpp"
using namespace std;

/**********************************************************************
 ** Function: Default constructor -- Character()
 ** Description: Creates necessary Car objects, creates Train object,
 **   runs game(train)
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
Character::Character() {
  movesLeft = 150;

  whiskeyCount = 0;  
  keyCount = 0;

  Car* engine = new Engine("engine room");
  Car* compartment = new Compartment("hidden compartment");
  Car* pass1 = new Passenger("passenger car 1");
  Car* bath1 = new Bathroom("bathroom");
  Car* dining = new Dining("dining car");
  Car* pass2 = new Passenger("passenger car 2");
  Car* bath2 = new Bathroom("bathroom");
  Car* guard = new Passenger("passenger car 3");
  Car* between = new BtwCars("outside baggage car");
  Car* baggage = new Baggage("baggage car");

  Car* engineTop = new Top("engine room roof");
  Car* pass1Top = new Top("passenger car 1 roof");
  Car* diningTop = new Top("dining car roof");
  Car* pass2Top = new Top("passenger car 2 roof");
  Car* guardTop = new Top("passenger car 3 roof"); 
  Car* baggageTop = new Top("baggage car roof");

  Train* train = new Train(engine, compartment, pass1, bath1, dining, pass2, bath2, guard, between, baggage, engineTop, pass1Top, diningTop, pass2Top, guardTop, baggageTop);

  game(train);
}

/**********************************************************************
 ** Function: game()
 ** Description: Manages the game by providing prompts
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
void Character::game(Train* train) {
  cout << "\nThe year is 1860. Construction of the first transcontinental railroad was completed less than a year ago. It's a good time to be a train robber. Usually you just walk up and down the cars relieving rich folks' bags of their shiny belongings, but a couple of weeks ago, you were approached by a fella in a swanky suit who told you that he wanted to hire you. The job was to steal a particular bag from a particular train, and it would pay enough for you to get your own swanky suit and a Manhattan apartment to go with it. You could finally move onto the life of bigger and better things that you always knew you were meant for. Needless to say, you didn't hesitate to sign on the dotted line. What's in the bag? Didn't ask, didn't care. \nNow, you're sitting on that very train. It has six cars in all: an engine, a passenger car, a dining car, two more passenger cars, and the baggage car. You're sitting in the first passenger car, four cars in front of the baggage car that contains the loot, and you only have a little while to get the job done. It's just your typical passenger car. Everyone's pretty quiet at this point in the ride. There's a bathroom in the corner, but you've never really wanted to see the inside of a train-john.There are bags full of who knows what kind of valuables all over, but you promised your employer that you wouldn't attract any unwanted attention by stealing anything he didn't tell you to." << endl;
  
  while(action != "exit" && !train->getEnd() && movesLeft > 0) {
    cout << "\n" << movesLeft << " moves left." << endl;
    cout << "\nWould you like to inspect something, use an item, or move? \n(Enter 'inspect,' 'use,' or 'move,' or enter 'exit' to quit)" << endl;
    cin >> action;

    if(action == "inspect") {
      inspect(train);
    }
    else if(action == "use") {
      use(train);
    }
    else if(action == "move") {
      move(train);
    }
    else if(action == "exit") {
      cout << "\nAre you sure you want to quit? (y/n)" << endl;
      cin >> action;

      if(action == "y") {
        cout << "\nOkay, goodbye." << endl;
        
        action = "exit";
      }
    }
    else {
      cout << "\nWhat was that?" << endl;
    }

    if(keyCount == 0 && train->getBtw()) {
      inventory.push_back("key");
      
      keyCount++;
    }
    else if(whiskeyCount == 0 && train->getEngine()) {
      inventory.push_back("whiskey");
      
      whiskeyCount++;
    }

    movesLeft--;
  } 
}

/**********************************************************************
 ** Function: move()
 ** Description: Prints space options and moves character
 ** Parameters: Pointer to train object
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
void Character::move(Train* train) {
  cout << "\nWhere would you like to go? ('none' to cancel)" << endl;
  buildSpaces(train);

  for(int i = 0; i < spaces.size(); i++) {
    if(!spaces[i].empty()) {
      cout << "  " << spaces[i] << endl;
    }
  }
  cout << endl;
  getline(cin, movement);
  getline(cin, movement);

  if(movement != "none") {
    train->moveChar(movement);
  }
}

/**********************************************************************
 ** Function: buildSpaces()
 ** Description: Copies space vector from train by using getSpaces()
 ** Parameters: Pointer to train object
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
void Character::buildSpaces(Train* train) {
  spaces = train->getSpaces();
}

/**********************************************************************
 ** Function: checkInv()
 ** Description: Prints inventory
 ** Parameters: Pointer to train object
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
void Character::checkInv(Train* train) {
  for(int i = 0; i < inventory.size(); i++) {
    if(!inventory[i].empty()) {
      cout << "  " << inventory[i] << endl;
    }
  }
}

/**********************************************************************
 ** Function: use()
 ** Description: Prints prompt and calls use() for user-selected item
 ** Parameters: Pointer to train object
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
void Character::use(Train* train) {
  cout << "\nWhat would you like to use? ('none' to cancel)" << endl;
  checkInv(train);
  cout << endl;
  cin >> item;

  if(item == "whiskey" || item == "key") {
    train->use(item);
  }
  else if(item != "none") {
    cout << "\nUse what now?" << endl;
  }
}

/**********************************************************************
 ** Function: inspect()
 ** Description: Prints prompt and calls inspect() for user-selected item
 ** Parameters: Pointer to train object
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
void Character::inspect(Train* train) {
  cout << "\nWhat would you like to inspect? ('none' to cancel)" << endl;
  cin >> inspection;
  
  if(inspection != "none") {
    train->inspect(inspection);
  }
}
