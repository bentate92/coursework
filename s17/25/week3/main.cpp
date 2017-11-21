//
//  main.cpp
//  Project 1
//
//  Created by eli goodwin on 4/19/17.
//  Copyright © 2017 eli goodwin. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "helperFunctions.hpp"
#include <vector>
using namespace std;



int main(int argc, const char * argv[]){

	if(argc < 2) {
		cout << "Usage: maxsum <algorithm #(1-4)>" << endl;
		return 1;
	}

	int algoInUse = atoi(argv[1]); 

	const int rows = 7; //number of rows
	vector<vector<int>> theNumbers(rows); //2d vector of size 7 by x

	struct values sums[rows]; //used to store results of the algos

	for(int i = 0; i < rows; ++i){
		sums[i].startIndex = 0;
		sums[i].endIndex = 0;
		sums[i].sum = 0;
		sums[i].timeElapsed = 0;
	}
	//load the file in
	loadFile(theNumbers);

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
		cout << "Sorry, algorithm 4 is not yet implemented." << endl;
		return 0;
	} else {
		cout << "Usage: maxsum <algorithm #(1-4)>" << endl;
		return 1;
	}

	for(int i = 0; i < rows; ++i){
		cout << "Max subarray: " << i + 1 <<  " Run time: " << sums[i].timeElapsed << endl;
		for(int j = 0; j != sums[i].maxArray.size(); ++j){
			cout << sums[i].maxArray[j] << " ";
		}
		cout << endl;
	}

	writeFile(sums);

	return 0;
}
