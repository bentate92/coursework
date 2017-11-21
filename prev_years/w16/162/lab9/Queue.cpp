
/**********************************************************************
 ** Program Filename: Queue.cpp
 ** Author: Benjamin Tate
 ** Date: 3/6/16
 ** Description: Implementation of the Queue class, described in
 **   Queue.hpp
 ** Input: Responses to prompts
 ** Output: Various prompts
 *********************************************************************/

#include "Queue.hpp"
using namespace std;

/**********************************************************************
 ** Function: Default constructor -- Queue()
 ** Description: Provides prompts for user input, calls randInt(), and 
 **   calculates and prints the average length of the queue
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
Queue::Queue() {
  /*Initialize sum to 0*/
  sum = 0;

  /*Prompt user for turns to run sim and store response in turns*/
  cout << "\nLet's build a queue!"
       << "\nHow many turns do you want to run the simulation for?" 
       << endl;
  cin >> turns;

  /* 
   * Prompt user for chance of adding a value 
   * and store response in addChance
   */
  cout << "\nPlease specify a percent chance that a value is added"
       << " each turn."
       << "\nEnter a value from 0-100)" << endl; 
  cin >> addChance;

  /* 
   * Prompt user for chance of removing a value 
   * and store response in remChance
   */
  cout << "\nPlease specify a percent chance that a value is removed"
       << " each turn."
       << "\nEnter a value from 0-100)" << endl; 
  cin >> remChance;

  /*Inform user that input has been received*/
  cout << "\nThank you! Running the simulation." << endl;

  /*Continue for specified number of turns*/
  for(int i = 0; i < turns; i++) {
    /*Call randInt() on addChance and remChance*/
    randInt(addChance, remChance);

    /*Add the queue's size for the turn to sum*/
    sum += q.size();
  }

  /*Calculate average size of queue as double*/
  avg = (double)sum / turns;

  /*Print average size of queue*/
  cout << "\nThe average length of the queue for this round was "
       << avg << "." << endl;
}

/**********************************************************************
 ** Function: randInt()
 ** Description: Has specified probability of adding a random int to 
 **   the queue, and specified probability of removing one from it
 ** Parameters: Int representing % chance of adding to the queue, and 
 **   an int representing % chance of removing one
 ** Pre-Conditions: add and rem must contain values between 0 and 100
 ** Post-Conditions: None
 *********************************************************************/
void Queue::randInt(int add, int rem) {
  /*Initialize addIt to random int from 1 to 100*/
  addIt = rand() % 100 + 1;

  /*
   * Add random value from 1-100 to queue if addIt isn't above add
   * (This ensures that there is an add% chance that a val will be added)
   */
  if(addIt <= add) {
    val = rand() % 100 + 1;

    q.push(val);
  }

  remIt = rand() % 100 + 1;

  /*
   * Remove a value from the front of the queue if remIt isn't above rem
   * (This ensures that there is an rem% chance that a val will be removed)
   */
  if(remIt <= rem && q.size() > 0) {
    q.pop();
  }
}
