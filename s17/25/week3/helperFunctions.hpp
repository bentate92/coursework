//
//  helperFunctions.hpp
//  Project 1
//
//  Created by eli goodwin on 4/20/17.
//  Copyright © 2017 eli goodwin. All rights reserved.
//

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

void loadFile(std::vector<std::vector<int>>& theNumbers);
void writeFile(struct values theSums[]);
void writeFile(long runTime[], int dataSize);
void algo1(std::vector<int>& theNumbers, struct values& sums);
void algo2(std::vector<int>& theNumbers, struct values& sums);
int algo3(std::vector<int>& theNumbers, int startIdx, int endIdx, struct values& sums);

void makeRandom(std::vector<int>& theNumbers, int theSize);


#endif /* helperFunctions_hpp */


