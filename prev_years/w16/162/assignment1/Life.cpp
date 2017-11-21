/*********************************************************************
 ** Program Filename: Life.cpp
 ** Author: Benjamin Tate
 ** Date: 1/17/16
 ** Description: Implementation of Life class described in Life.hpp
 ** Input: String representing the user's pattern selection and two
 ** ints representing coordinates of the cell the pattern will begin at
 ** Output: A 40x20 matrix containing the state of the pattern at a 
 ** particular generation
 *********************************************************************/

#include "Life.hpp"

using namespace std;

/*********************************************************************
 ** Function: Life()
 ** Description: Constructor initialize cells of mainArray and 
 ** neighborCount to zero, convert user's letter selection to a
 ** Pattern, convert starting coordinates from describing a cell in
 ** the visible window to ones describing a cell in the full array,
 ** run buildStart() function to populate mainArray with the selected
 ** pattern, at the selected spot
 ** Parameters: String representing user's pattern selection, two ints
 ** representing starting coordinates within the visible window
 ** Pre-Conditions: User must have been prompted for a pattern
 ** selection and starting coordinates
 **   chosen (either 4 or 9)
 ** Post-Conditions: None
 *********************************************************************/
Life::Life(string selection, int winR, int winC) {
  /*Initialize each cell in mainArray to 0*/
  for(int r = 0; r < 30; r++) {
    for(int c = 0; c < 76; c++) {
      mainArray[r][c] = 0;
    }
  }
  /*Initialize each cell in neighborCount to 0*/
  for(int r = 0; r < 30; r++) {
    for(int c = 0; c < 76; c++) {
      neighborCount[r][c] = 0;
    }
  }

  /*Update the Pattern enumerator, userChoice, to the selected pattern*/
  if(selection == "a") {
    userChoice = OSCILLATOR;
  }
  else if(selection == "b") {
    userChoice = GLIDER;
  }
  else if(selection == "c") {
    userChoice = GUN;
  }

  /*Update windowRow and windowCol to user-selected coordinates*/  
  windowRow = winR;
  windowCol = winC;
  /*Convert coordinates within visible window to context of full matrix*/
  startRow = windowRow + 4;
  startCol = windowCol + 17;  

  /*
   * Call buildStart() to populate mainArray with selected pattern, 
   * at selected coordinates
   */
  buildStart(mainArray, userChoice, startRow, startCol);
}

/*********************************************************************
 ** Function: buildStart()
 ** Description: Updates mainArray to display the selected pattern, at
 ** the selected coordinates
 ** Parameters: 76x30 array of ints, Pattern enumerator, two ints
 ** that represent starting coordinates
 ** Pre-Conditions: mainArray must be initialized and filled with
 ** zeroes, starting coordinates and pattern must be selected
 ** Post-Conditions: None
 *********************************************************************/
void Life::buildStart(int array[30][76], Pattern pattern, int row, int col) {
  /*Draw starting oscillator pattern*/
  if(pattern == OSCILLATOR) {
    array[row][col] = 1;
    array[row][col - 1] = 1;
    array[row][col + 1] = 1;
  }
  /*Draw starting glider pattern*/
  else if(pattern == GLIDER) {
    array[row - 1][col] = 1;
    array[row][col + 1] = 1;
    array[row + 1][col - 1] = 1;
    array[row + 1][col] = 1;
    array[row + 1][col + 1] = 1;
  }
  /*Draw starting glider gun pattern*/
  else if(pattern == GUN) {
    array[row - 4][col + 6] = 1;
    array[row - 3][col + 4] = 1;
    array[row - 3][col + 6] = 1;
    array[row - 2][col - 6] = 1;
    array[row - 2][col - 5] = 1;
    array[row - 2][col + 2] = 1;
    array[row - 2][col + 3] = 1;
    array[row - 2][col + 16] = 1;
    array[row - 2][col + 17] = 1;
    array[row - 1][col - 7] = 1;
    array[row - 1][col - 3] = 1;
    array[row - 1][col + 2] = 1;
    array[row - 1][col + 3] = 1;
    array[row - 1][col + 16] = 1;
    array[row - 1][col + 17] = 1;
    array[row][col - 18] = 1;
    array[row][col - 17] = 1;
    array[row][col - 8] = 1;
    array[row][col - 2] = 1;
    array[row][col + 2] = 1;
    array[row][col + 3] = 1;
    array[row + 1][col - 18] = 1;
    array[row + 1][col - 17] = 1;
    array[row + 1][col - 8] = 1;
    array[row + 1][col - 4] = 1;
    array[row + 1][col - 2] = 1;
    array[row + 1][col - 1] = 1;
    array[row + 1][col + 4] = 1;
    array[row + 1][col + 6] = 1;
    array[row + 2][col - 8] = 1;
    array[row + 2][col - 2] = 1;
    array[row + 2][col + 6] = 1;
    array[row + 3][col - 7] = 1;
    array[row + 3][col - 3] = 1;
    array[row + 4][col - 6] = 1;
    array[row + 4][col - 5] = 1;
  }
}

/*********************************************************************
 ** Function: nextGen()
 ** Description: Updates the matrix to represent the next generation,
 ** according to the rules of the Game of Life
 ** Parameters: None
 ** Pre-Conditions: mainArray must already contain starting pattern at
 ** given coordinates
 ** Post-Conditions: None
 *********************************************************************/
void Life::nextGen() {
  /*Initialize temporary matrix to track which cells change*/
  int temp[30][76];

  /*Fill temp with zeroes to start*/
  for(int r = 0; r < 30; r++) {
    for(int c = 0; c < 76; c++) {
      temp[r][c] = 0;
    }
  }

  /*
   * Call setNeighbors() to count living neighbors for each cell in
   * mainArray
   */
  setNeighbors(mainArray);

  /*
   * For each cell in mainArray matrix, determine if the rules will
   * warrant a change in the next generation, and reflect changes in
   * temp matrix
   */
  for(int i = 0; i < 30; i++) {
    for(int j = 0; j < 76; j++) {
      if((mainArray[i][j] == 1 && (neighborCount[i][j] > 1 && neighborCount[i][j] <= 3)) ||
         (mainArray[i][j] == 0 && (neighborCount[i][j] != 3))) {
        temp[i][j] = mainArray[i][j];
      }
      else {
        if(mainArray[i][j] == 1) {
          temp[i][j] = 0;
        }
        else {
          temp[i][j] = 1;
        }
      }
    }
  }

  /*Call copy() to update mainArray to reflect changes in temp*/
  copy(mainArray, temp);
}

/*********************************************************************
 ** Function: setNeighbors()
 ** Description: Updates neighborCount to have each cell contain the
 ** number of living neighbors the corresponding coordinate has in
 ** mainArray
 ** Parameters: 76x30 array of ints
 ** Pre-Conditions: mainArray must exist
 ** Post-Conditions: None
 *********************************************************************/
void Life::setNeighbors(int arr[30][76]) {
  /*For each cell in mainArray, count total number of living neighbors*/
  for(int i = 1; i < 29; i++) {
    for(int j = 1; j < 75; j++) {
      int count = arr[i - 1][j - 1] +
                  arr[i - 1][j] +
                  arr[i - 1][j + 1] +
                  arr[i][j - 1] +
                  arr[i][j + 1] +
                  arr[i + 1][j - 1] +
                  arr[i + 1][j] +
                  arr[i + 1][j + 1];
      
      /*
       * Update each cell to contain number of living neighbors of 
       * corresponding mainArray cell     
       */
      neighborCount[i][j] = count;
    }
  }
}

/*********************************************************************
 ** Function: copy()
 ** Description: Simple function to copy one 2D array into another --
 ** used in this program to instantaneously update mainArray at each
 ** generation.
 ** Parameters: Two 76x30 arrays of ints
 ** Pre-Conditions: mainArray and another, temporary array must exist
 ** Post-Conditions: None
 *********************************************************************/
void Life::copy(int arr1[30][76], int arr2[30][76]) {
  /*Copy temp to mainArray, cell by cell*/
  for(int i = 0; i < 30; i++) {
    for(int j = 0; j < 76; j++) {
      arr1[i][j] = arr2[i][j]; 
    }
  }
}

/*********************************************************************
 ** Function: getCellVal()
 ** Description: Allows access to contents of the private mainArray
 ** from functions outside of the Life class
 ** Parameters: Two ints representing the coordinates of the cell
 ** whose value is to be returned
 ** Pre-Conditions: mainArray must have been initialized
 ** Post-Conditions: None
 *********************************************************************/
int Life::getCellVal(int r, int c) {
  /*
   * Initialize cellVal int and set equal to value at given mainArray
   * cell
   */
  int cellVal = mainArray[r][c];

  /*Return cellVal to allow access in main() function*/
  return cellVal;
}



