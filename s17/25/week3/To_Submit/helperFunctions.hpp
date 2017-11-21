/*********************************************************************
 ** Program Filename: helperFunctions.hpp
 ** Author: Eli Goodwin and Benjamin Tate
 ** Date: 2016/4/21
 ** Description: Funcitons used to faciliate the calculation of the maximum sub array given
 ** an array filled with random integers
 ** Input: none
 ** Output: none
 *********************************************************************/

#ifndef helperFunctions_hpp
#define helperFunctions_hpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <vector>
#include <iterator>
#include <time.h>
#include <climits>

/*********************************************************************
 ** struct values stores the starting and ending index of the max subarray along with the sum of the max sub array and the time elapsed to find the maximum subarray.
 *********************************************************************/
struct values{
    int startIndex;
    int endIndex;
    long long sum;
    long long timeElapsed;
    std::vector<int> maxArray;
    values(){
        startIndex = 0;
        endIndex = 0;
        sum = 0;
        timeElapsed = 0;
    }
};

/*********************************************************************
 ** Function: loadFile
 ** Description: loads a txt file that contains a string of positive and negative integers
 ** into a 2-d vector.
 ** Parameters: vector<vector<int>>
 ** Pre-Conditions: vector must be a 2-d vector of ints with empty rows
 ** Post-Conditions: 2-d vector is filled with ints from the txt file
 ** Return: none
 *********************************************************************/
void loadFile(std::vector<std::vector<int>>& theNumbers);

/*********************************************************************
 ** Function: writeFile
 ** Description: writes data from a struct into a text file, specifically the max sub array
 ** as calculated from the one of the 4 algorithms
 ** Parameters: struct values theSums[] is an arrray of struct values containing the max sub array and
 ** the sum of the max subarray
 ** Pre-Conditions: struct values array must not be empty
 ** Post-Conditions: none
 ** Return: none
 *********************************************************************/
void writeFile(struct values theSums[], int algoInUse);

/*********************************************************************
 ** Function: writeFile
 ** Description: take an array of runtime values calculated from various max sub array algos and save them to a csv file
 ** Parameters: long runTime[] is the runtime calculations, while dataSize is the the of tests that were performed
 ** Pre-Conditions: runtime array must not be empty, and datasize must be greater than 0
 ** Post-Conditions: none
 ** Return: none
 *********************************************************************/
void writeFile(long runTime[], int dataSize);

/*********************************************************************
 ** Function: algo1
 ** Description: takes an array of random integers and calculates the maximum subarray contained in the array if one exists O(n^3) runtime using 3 for-loops
 ** Parameters: vector<int> theNumbers refers to the array in question, struct values sums stores the results from finding the max sub array
 ** Pre-Conditions: the vector must not be empty
 ** Post-Conditions: none
 ** Citation: Derived from pseudo code found in lectures
 ** Return: none
 *********************************************************************/
void algo1(std::vector<int>& theNumbers, struct values& sums);

/*********************************************************************
** Function: algo2
** Description: take an array of runtime values calculated from various max sub array algos and save them to a csv file with O(n^2) runtime usign 2 for-loops
** Parameters: vector<int>& theNumbers is the array in question while struct values& sums stores the results
** Pre-Conditions: vector must not be empty
** Post-Conditions: none
** Citation: Derived from pseudo code found in lectures
** Return: none
*********************************************************************/
void algo2(std::vector<int>& theNumbers, struct values& sums);

/*********************************************************************
 ** Function: algo3
 ** Description: take an array of runtime values calculated from various max sub array algos and save them to a csv file with O(n lgn) runtime usigng a recursive divide and conquer approach to finding the max sub array.
 ** Parameters: vector<int>& theNumbers is the numbers in question, startIdx is the starting index of the sub array, endIdx is the ending index of the sub array, while values& sum stores the results
 ** Pre-Conditions: vector must not be empty
 ** Post-Conditions: none
 ** Citation: Derived from pseudo code found in lectures
 ** Return: none
 *********************************************************************/
int algo3(std::vector<int>& theNumbers, int startIdx, int endIdx, struct values& sums);

/*********************************************************************
 ** Function: algo4
 ** Description: take an array of runtime values calculated from various max sub array algos and save them to a csv file with O(n lgn) runtime usigng a recursive divide and conquer approach to finding the max sub array.
 ** Parameters: vector<int>& theNumbers is the numbers in question, startIdx is the starting index of the sub array, endIdx is the ending index of the sub array, while values& sum stores the results
 ** Pre-Conditions: vector must not be empty
 ** Post-Conditions: none
 ** Citation: Derived from pseudo code found in lectures and Introduction of Algorithms by Cormen et al
 ** Return: none
 *********************************************************************/
int algo4(std::vector<int>& theNumbers, struct values& sums);

/*********************************************************************
 ** Function: makeRandom
 ** Description: makeRandom is used to make a vector of size n contain positive and negative integers within the range of +- size/4 so that when the maximum sub array calculations are performed an overflow does not occur.
 ** Parameters: vector<int>& theNumbers is the array in quesiton and theSize is the size of vector and also determines the range of values contained within the vector
 ** Pre-Conditions: theSize != 0
 ** Post-Conditions: none
 ** Return: none
 *********************************************************************/
void makeRandom(std::vector<int>& theNumbers, int theSize);



#endif /* helperFunctions_hpp */


