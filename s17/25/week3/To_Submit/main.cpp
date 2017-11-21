/*********************************************************************
 ** Program Filename: main.cpp // maxsum
 ** Author: Eli Goodwin and Benjamin Tate
 ** Date: 2016/4/21
 ** Description: This program calculates the maximum sub array of arrays contained within a provided txt file. The maximum sub array is calculated with 
 ** 3 different algorithms each with different performmance. Once the max sub arrray is found its associated data, start and ending indices, the sum, and the max subarray itself are saved in a txt file.
 ** Input: .txt file containing the test arrays.
 ** Output: .txt file containg the maximum sub array and its sum for each algorithm and each array contained within the provided text file
 *********************************************************************/
#include <iostream>
#include <fstream>
#include "helperFunctions.hpp"
#include <vector>
using namespace std;



int main(){

	int algoInUse = 1; //used to loop through the various algorithms and test their validity

	const int rows = 7; //number of rows
	vector<vector<int>> theNumbers(rows); //2d vector of size 7 by x

	struct values sums[rows]; //used to store results of the algos

	//load the file in
	loadFile(theNumbers);
    while(algoInUse < 5){
        cout << "The array is: \n";
        for(int j = 0; j < theNumbers.size(); ++j){
            for(int i = 0; i < theNumbers[j].size(); ++i) {
                cout << theNumbers[j][i] <<  " ";
            }
            cout << endl;
        }

        if(algoInUse == 1) {
            //algo1
            for(int i = 0; i < theNumbers.size(); i++) {
                //run the algo
                algo1(theNumbers[i], sums[i]);

                //get the size of the resulting array
                int size = sums[i].endIndex - sums[i].startIndex + 1;

                //shove into the data structure --  maxarray will store the maximum sub array as calculated from the algo
                for(int j = 0; j < size; ++j){
                    int n = theNumbers[i][j+sums[i].startIndex];
                    sums[i].maxArray.push_back(n);
                }
            }
        } else if(algoInUse == 2) {
            //algo2
            for(int i = 0; i < theNumbers.size(); ++i){
                //run the algo
                algo2(theNumbers[i], sums[i]);

                //get the size of the resulting array
                int size = sums[i].endIndex - sums[i].startIndex + 1;

                //shove into the data structure --  maxarray will store the maximum sub array as calculated from the algo
                for(int j = 0; j < size; ++j){
                    int n = theNumbers[i][j+sums[i].startIndex];
                    sums[i].maxArray.push_back(n);
                }
            }
        } else if(algoInUse == 3) {
            //algo3
            for(int i = 0; i < theNumbers.size(); i++) {
                auto start = chrono::high_resolution_clock::now(); //initialize timer
                //Run the algorithm
                algo3(theNumbers[i], 0, theNumbers[i].size() - 1, sums[i]);
                auto elapsed = chrono::high_resolution_clock::now() - start; //get elapsed time
                sums[i].timeElapsed = chrono::duration_cast<std::chrono::microseconds>(elapsed).count(); //save time elapsed

                //get the size of the resulting array
                int size = sums[i].endIndex - sums[i].startIndex + 1;

                //shove into the data structure --  maxarray will store the maximum sub array as calculated from the algo
                for(int j = 0; j < size; j++) {
                    int n = theNumbers[i][j+sums[i].startIndex];
                    sums[i].maxArray.push_back(n);
                }
            }
        } else if(algoInUse == 4) {
            //algo4
            for(int i = 0; i < theNumbers.size(); ++i){
                algo4(theNumbers[i], sums[i]);
                int size = sums[i].endIndex - sums[i].startIndex + 1;
            
            //shove into the data structure --  maxarray will store the maximum sub array as calculated from the algo
                for(int j = 0; j < size; ++j){
                    int n = theNumbers[i][j+sums[i].startIndex];
                    sums[i].maxArray.push_back(n);
                }
            }
        }

        
        for(int i = 0; i < rows; ++i){
            cout << "Max subarray: " << i + 1 <<  " Run time: " << sums[i].timeElapsed << endl;
            for(int j = 0; j != sums[i].maxArray.size(); ++j){
                cout << sums[i].maxArray[j] << " ";
            }
            cout << endl;
        }
        
        
        //write out results
        writeFile(sums, algoInUse);
        //reset the vectors and clear them
        for(int i = 0; i < theNumbers.size(); ++i) {
            sums[i].maxArray.clear();
        }
        
        //increment counter for the algo to use
        ++algoInUse;
    }

	return 0;
}
