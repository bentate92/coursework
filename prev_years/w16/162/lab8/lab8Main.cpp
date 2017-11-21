
/**********************************************************************
 ** Program Filename: lab8Main.cpp
 ** Author: Benjamin Tate
 ** Date: 2/28/16
 ** Description: Contains main function to manage the Queue according
 **   to user input
 ** Input: Responses to prompts
 ** Output: Various prompts
 *********************************************************************/

#include "Queue.hpp"
#include <string>
#include <iostream>
using namespace std;

int main() {
  /*Create string to hold user choices*/
  string selection;
  /*Create a Queue object*/
  Queue q;

  /*Continue until user choses "Exit" option*/
  while(selection != "x)") {
    /*Prompt user for their choice of actions*/
    cout << "\nWhat would you like to do with the queue?" 
         << "\n a) Enter a value"
         << "\n b) Display first value"
         << "\n c) Remove a value"
         << "\n d) Display the queue contents (and empty queue)"
         << "\n x) Exit" << endl;
    /*Accept user input*/
    cin >> selection;
    
    /*Validate user input and respond with appropriate action or error*/
    if(selection == "a)") {
      /*Create int to hold the value to be added*/
      int newVal;

      /*Prompt user for the value*/
      cout << "\nPlease enter a positive integer:" << endl;
      /*Accept user input*/
      cin >> newVal;
      /*Give feedback*/
      cout << "\nAdding " << newVal << "..." << endl;
  
      /*Add newVal to the Queue*/
      q.addBack(newVal);
    }
    else if(selection == "b)") {
      /*If the Queue isn't empty*/
      if(q.getFront() != -1) {
        /*Call getFront() and tell user the front value*/
        cout << "\nThe first value in the queue is " << q.getFront() << "." << endl;
      }
      /*If the Queue is empty, inform user*/
      else {
        cout << "\nThe queue is empty!" << endl;
      }
    }
    else if(selection == "c)") {
      /*If the Queue isn't empty*/
      if(q.getFront() != -1) {
        /*Call removeFront() and tell user the value being removed*/
        cout << "\nRemoving " << q.removeFront() << " from front of queue." << endl;
      }
      /*If the Queue is empty, inform user*/
      else {
        cout << "\nThe queue is empty!" << endl;
      }
    }
    else if(selection == "d)") {
      /*If the Queue isn't empty*/
      if(q.getFront() != -1) {
        cout << "\nHere are the contents of the queue:" << endl;
        /*Continue until the Queue is empty*/
        while(q.getFront() != -1) {
          /*Call removeFront() and display value being removed*/
          cout << q.removeFront() << endl;
        }
      }
      /*If the Queue is empty, inform user*/
      else {
        cout << "\nThe queue is empty!" << endl;
      }
    }
    else if(selection == "x)") {
      /*Give feedback*/
      cout << "\nQuitting." << endl;
    }
  }

  return 0;
}
