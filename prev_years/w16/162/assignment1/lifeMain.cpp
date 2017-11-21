/*********************************************************************
 ** Program Filename: lifeMain.cpp
 ** Author: Benjamin Tate
 ** Date: 1/17/16
 ** Description: Main function to prompt user for starting pattern and
 ** placement, and the number of generations to run the simulation for
 ** Input: String representing the starting pattern, two ints to 
 ** represent starting coordinates, and another int representing the
 ** number of generations
 ** Output: Prompts for user input, and a 40x20 matrix showing the
 ** state of the pattern at each generation for the number of
 ** generations indicated
 *********************************************************************/

#include <iostream>
#include "Life.hpp"

using namespace std;

int main() {
  /*Initialize string to hold user's pattern selection*/
  string patternSelect;

  /*Initialize ints to hold starting coordinates within visible window*/
  int windowR;
  int windowC;

  /*Initialize int to hold number of generations to run simulation*/
  int gen;

  /*Prompt user for pattern selection*/
  cout << "Please select a starting pattern (choose a, b, or c):" << endl;
  cout << "a - oscillator" << endl;
  cout << "b - glider" << endl;
  cout << "c - glider gun" << endl;
  cout << "Selection:" << endl;
  cin >> patternSelect;

  /*Ensure that user selection is valid*/
  while(patternSelect != "a" && patternSelect != "b" && patternSelect != "c") {
    cout << "\nYou didn't enter a, b, or c!" << endl;
    cout << "\nPlease select a starting pattern (choose a, b, or c):" << endl;
    cout << "a - oscillator" << endl;
    cout << "b - glider" << endl;
    cout << "c - glider gun" << endl;
    cout << "Selection:" << endl;  
    cin >> patternSelect;
  }  

  /*Prompt user for starting coordinates*/
  cout << "\nWhich cell of the grid would you like the center of your pattern to begin?" << endl;
  cout << "Row (1-20):" << endl;
  cin >> windowR;
  cout << "Column (1-40):" << endl;
  cin >> windowC;

  /*Create Life object using user's responses from above*/
  Life sim(patternSelect, windowR, windowC);

  /*Prompt user for number of generations to run simulation*/
  cout << "\nHow many generations would you like to run the simulation for?" << endl;
  cin >> gen;

  /*Print visible window including starting pattern (generation 1)*/
  cout << "\n|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|" << endl;   
  for(int r = 5; r < 25; r++) {
    cout << "|";

    for(int c = 18; c < 58; c++) { 
      if(sim.getCellVal(r, c) == 1) {
        cout << "X|";
      }
      else if(sim.getCellVal(r, c) == 0) {
        cout << " |";
      }
    }
    cout << "\n|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|" << endl;   
  }

  /*Print a new table for each new generation*/  
  for(int g = 1; g <= gen; g++) {
    sim.nextGen();
    
    cout << "\n|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|" << endl;   

    for(int r = 5; r < 25; r++) {
      cout << "|";

      for(int c = 18; c < 58; c++) { 
        if(sim.getCellVal(r, c) == 1) {
          cout << "X|";
        }
        else if(sim.getCellVal(r, c) == 0) {
          cout << " |";
        }
      }
      
      cout << "\n|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|" << endl;   
    }
  }
}






