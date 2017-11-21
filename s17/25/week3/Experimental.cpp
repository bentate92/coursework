//
//  main.cpp
//  testingPro1
//
//  Created by eli goodwin on 4/21/17.
//  Copyright © 2017 eli goodwin. All rights reserved.
//
#include "helperFunctions.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]){
    
    srand((unsigned)time(NULL));

    const int TIMESTORUN = 20; //number of times each size n is run through the algo specified
    const int DATASIZE = 12;
    const int SIZE_N[DATASIZE] ={100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 10000000};
    int algoInUse = atoi(argv[1]); //start with algo 1
    long averageRunTime[DATASIZE]; //average run time for each array size
    
    //need struct to save run times
    struct values testedSums[TIMESTORUN];
    vector<int> testArray; //array, will be reused
    
    //each n will be times to run and the run time will be saved to
    cout << "Doing stuff for algo: " << algoInUse << endl;

    //run through the algo with incrementing arrray sizes and record the runtime
    for(int j = 0; j < 10; ++j){
        //set the size of the test array
        int size = SIZE_N[j];
        //rest time accumulator
        long time = 0;
        //run each algo 20x's, store the run time result, take average
        for(int i = 0; i < TIMESTORUN; ++ i){
            //make a random vector of size n
            makeRandom(testArray, size);
            //find the max sub array
            if(algoInUse == 1){
                algo1(testArray, testedSums[i]);
            }
            //algo 2
            else if(algoInUse == 2){
                algo2(testArray, testedSums[i]);
            }
            else if(algoInUse == 3) {
    			auto start = chrono::high_resolution_clock::now(); //initialize timer
                algo3(testArray, 0, testArray.size() - 1, testedSums[i]);
				auto elapsed = chrono::high_resolution_clock::now() - start; //get elapsed time
				testedSums[i].timeElapsed = chrono::duration_cast<std::chrono::microseconds>(elapsed).count(); //save time elapsed
			}
//            else
//                //algo4
            //accumulate time
            time += testedSums[i].timeElapsed;
            //clearout the vector
            testArray.clear();
        }
        //calculate the average run time for size n
        averageRunTime[j] = time/TIMESTORUN;
        //shove the results into the csv file
        writeFile(averageRunTime, 10);
    }
    


    cout << "Finished" << endl;
    
    return 0;
}
