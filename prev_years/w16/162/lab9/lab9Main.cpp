
/**********************************************************************
 ** Program Filename: lab9Main.cpp
 ** Author: Benjamin Tate
 ** Date: 3/6/16
 ** Description: Main function to provide menue and manage Queue and 
 **   Stack objects
 ** Input: Responses to prompts
 ** Output: Menu of options
 *********************************************************************/

#include "Queue.hpp"
#include "Stack.hpp"

int main() {
  /*Set rand() by time, for use in Queue class*/
  srand(time(NULL));

  /*Initialize int choice to anything but 0*/
  int choice = 1;

  /*Continue until choice equals 0*/
  while(choice != 0) {
    /*Print menu and accept user choice in choice*/
    cout << "\nWhat would you like to do?"
         << "\n1 - Simulate server job requests with a queue"
         << "\n2 - Create a palindrome with a stack"
         << "\n0 - Quit" << endl;
    cin >> choice;

    /*Create appropriate object, based on choice, quit, or print error*/
    if(choice == 1) {
      Queue qSim;
    }
    else if(choice == 2) {
      Stack sPal;
    }
    else if(choice == 0) {
      cout << "\nQuitting...\n" << endl;
    }
    else {
      cout << "\nI didn't quite get that." << endl;
    }
  }

  return 0;
}

