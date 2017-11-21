//
//  helperFunctions.cpp
//  Project 1
//
//  Created by eli goodwin on 4/20/17.
//  Copyright © 2017 eli goodwin. All rights reserved.
//

#include "helperFunctions.hpp"
using namespace std;

void loadFile(vector<vector<int>>& theNumbers){
	const char* FILENAME = "MSS_TestProblems.txt"; //filename
	string numString; //stores get line from txt file, used to convert to ints
	ifstream myFile; //file variable

	//open the file
	myFile.open(FILENAME);
	cout << "Opening file \""<< FILENAME << "\"..." << endl;
	//check if open

	if(!myFile){
		cout << "You goofed, file cannot be opened." << endl;
		return;
	}

	//read each line, convert to ints from string stream, store in array
	int i = 0;
	//while not at the end of the file shove things into the 2d vector
	while(!myFile.eof()){
		getline(myFile, numString);
		istringstream iss(numString);
		int n = 0;
		while(iss >>n){
			theNumbers[i].push_back(n);
		}
		++i;
	}

	//close the file
	myFile.close();
	//clear the file
	myFile.clear();
	return;
}

void writeFile(struct values theSums[], int algoInUse){
	const char* fileName = "MSS_TestResults.txt";

	ofstream outFile;
    outFile.open(fileName, ios::out | ios::app);
    
    
    if(outFile.is_open()){
        outFile << "Algo in use: " << algoInUse << endl;
		for(int i = 0; i < 7; ++i){
			outFile << "Array: "<< i << " Sum of max subarray: " <<  theSums[i].sum << " Elapsed Time: "<< theSums[i].timeElapsed << " " << endl;
			outFile << "Max Sub Array " << i << ": ";
			for(int j = 0; j != theSums[i].maxArray.size(); ++j){
				outFile << theSums[i].maxArray[j] << " ";
			}
			outFile << endl;
		}
        outFile << endl;
    }
	outFile.close();
	return;
}

void writeFile(long runTime[], int dataSize){
	const char* fileName = "results.csv";
	ofstream outFile(fileName);
	if(outFile.is_open()){
		for(int i = 0; i < dataSize; ++i){
			outFile << runTime[i];

			if(i != dataSize -1){
				outFile << ", ";
			}
		}
		outFile << endl;
	} else {
		cout << "You goofed" << endl;
	}
	return;
}

void algo1(vector<int>& theNumbers, struct values& sums){
	int tempSum = 0;
	auto start = chrono::high_resolution_clock::now(); //initialize timer

	//this is terrible, get starting index
	for(int i = 0; i != theNumbers.size(); ++i){
		//from the starting index compute the sums of all the sub arrays
		for(int j = i; j != theNumbers.size(); ++j){
			tempSum = 0;
			//gross, but compute the sum of the sub array specified by i and j
			for(int k = i; k <= j; ++k){
				//is the sum the best sum ever? if so we should save it
				tempSum += theNumbers[k];
				if(tempSum > sums.sum){
					//save the sum and the starting and ending indices
					sums.sum = tempSum;
					sums.startIndex = i;
					sums.endIndex = k;
				}
			}
		}
	}

	auto elapsed = chrono::high_resolution_clock::now() - start; //get elapsed time
	sums.timeElapsed = chrono::duration_cast<std::chrono::microseconds>(elapsed).count(); //save time elapsed
}


void algo2(vector<int>& theNumbers, struct values& sums){
	int tempSum = 0;
	auto start = chrono::high_resolution_clock::now(); //initialize timer

	//find the maximum sub array the ok way
	for(int i = 0; i != theNumbers.size(); ++i){
		tempSum = theNumbers[i];
		for(int j = i + 1; j != theNumbers.size(); ++j){
			tempSum += theNumbers[j];
			if(tempSum > sums.sum){
				sums.sum = tempSum;
				sums.startIndex = i;
				sums.endIndex = j;
			}
		}
	}

	auto elapsed = chrono::high_resolution_clock::now() - start; //get elapsed time
	sums.timeElapsed = chrono::duration_cast<std::chrono::microseconds>(elapsed).count(); //save time elapsed

	return;
}

int algo3(vector<int>& theNumbers, int startIdx, int endIdx, struct values& sums) {
	int n = theNumbers.size();

	//Base case
	if(n == 1) {
		if(theNumbers[0] > sums.sum) {
			sums.sum = theNumbers[0];
			sums.startIndex = startIdx;
			sums.endIndex = endIdx;
		}
		return sums.sum;
	}

	int mid = n / 2;

	//Split left and right half
	vector<int> left(theNumbers.begin(), theNumbers.begin() + mid);
	vector<int> right(theNumbers.begin() + mid, theNumbers.end());

	//Recursive calls on left and right halves
	int l_maxsum = algo3(left, startIdx, startIdx + mid - 1, sums);
	int r_maxsum = algo3(right, startIdx + mid, endIdx, sums);

	//Initializing sums of left and right
	int l_sum = INT_MIN;
	int r_sum = INT_MIN;
	int temp_sum = 0;
	//Initializing ints to hold base array indices
	int l_idx;
	int r_idx;

	//Loop backward through left half
	for(int i = mid - 1; i >= 0; i--) {
		//Add element to temp_sum
		temp_sum += theNumbers[i];
		//Update l_sum and l_idx if higher sum is found
		if(temp_sum > l_sum) {
			l_sum = temp_sum;
			l_idx = startIdx + i;
		}
	}

	//Reset temp_sum
	temp_sum = 0;

	//Loop forward through right half
	for(int i = mid; i < n; i++) {
		//Add element to temp_sum
		temp_sum += theNumbers[i];
		//Update r_sum and r_idx if higher sum is found
		if(temp_sum > r_sum) {
			r_sum = temp_sum;
			r_idx = startIdx + i;
		}
	}

	//Declare int to hold higher maxsum between left and right sides
	int lr_maxsum;

	//Declare tempMax to indicate current max sum subarray
	//(1 = left, 2 = right)
	int tempMax;

	//Set lr_maxsum and tempMax
	if(l_maxsum >= r_maxsum) {
		lr_maxsum = l_maxsum;
		tempMax = 1;
	} else {
		lr_maxsum = r_maxsum;
		tempMax = 2;
	}

	//Determine which case to use and update sums object accordingly
	if(lr_maxsum >= l_sum + r_sum) {
		if(lr_maxsum > sums.sum) {
			sums.sum = lr_maxsum;
			if(tempMax == 1) {
				//Case 1: maxsum contained entirely in first half
				sums.startIndex = startIdx;
				sums.endIndex = startIdx + mid - 1;
			} else {
				//Case 2: maxsum contained entirely in second half
				sums.startIndex = startIdx + mid;
				sums.endIndex = endIdx;
			}
		}
	} else {
		//Case 3: maxsum made of suffix of first half and prefix of second half
		if(l_sum + r_sum > sums.sum) {
			sums.sum = l_sum + r_sum;
			sums.startIndex = l_idx;
			sums.endIndex = r_idx;
		}
	}

	return sums.sum;
}		

void makeRandom(vector<int>& theNumbers,int theSize) {
	int randomNumber = 0;
	int range = theSize / 2;

	for(int i = 0; i < theSize; ++i){
		//this will genrate random numbers within (+/-)size/4 that way terrible overflows are not created
		randomNumber = rand() % (range) + 1 + (-(range/2));
		//shove random numbers into the vector
		theNumbers.push_back(randomNumber);
	}


	return;
}

int algo4(vector<int>& theNumbers, struct values& sums){
    
    
    int maxSum = theNumbers[0];
    sums.startIndex = 0;
    sums.endIndex = 0;
    
    
    int maxSuffixSum = theNumbers[0];
    int maxSuffixStartIdx = 0;
    
    for (int i = 1; i < theNumbers.size(); i++)
    {
        if (maxSuffixSum > 0)
            maxSuffixSum += theNumbers[i];
        else
        {
            maxSuffixSum = theNumbers[i];
            maxSuffixStartIdx = i;
        }
        
        
        if (maxSuffixSum > maxSum)
        {
            maxSum = maxSuffixSum;
            sums.startIndex = maxSuffixStartIdx;
            sums.endIndex = i;
        }
    }
    return maxSum;
}

