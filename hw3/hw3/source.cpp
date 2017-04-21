//
//  source.cpp
//  hw3
//
//  Created by Kyleen Gonzalez on 4/21/17.
//  Copyright © 2017 Kyleen Gonzalez. All rights reserved.
//
#include "Header.h"
#include <stdio.h>
#include <iostream>

using namespace std;

//Write code to output a) the average daily high and b) the average daily low
void averageHighLow(int array[][columns]){
    float averageHigh;
    float averageLow;
    
    for (int i = 0; i < columns; ++i) {
        averageHigh += array[1][i];
        averageLow += array[2][i];
    }
    averageHigh = averageHigh/31;
    averageLow = averageLow/31;
    cout << "The average daily high is: " << averageHigh <<endl;
    cout << endl;
    cout << "The average daily low is: " << averageLow <<endl;
}

//Write code to output a) the lowest high temperature during the month and b) the highest low temperature during the month
void lowestHigh(int array[][columns]){
    int lowestHigh = 52;
    for (int i = 0; i < columns; ++i) {
        if (lowestHigh > array[1][i]) {
            lowestHigh = array[1][i];
        }
    }
    cout << "The lowest high temperature is: " << lowestHigh <<endl;
}


void highestLow(int array[][columns]){
    int highestLow = 32;
    for (int i = 0; i < columns; ++i) {
        if (highestLow < array[2][i]) {
            highestLow = array[2][i];
        }
    }
    cout << "The highest low temperature is: " << highestLow <<endl;
}

//Write code to count a) the number of days when the high was 54 degrees and b) the numbers of days when the low was below freezing
void countHighLow(int array[][columns]){
    int counterHigh = 0;
    int counterLow = 0;
    for (int i = 0; i < columns; ++i) {
        if (array[1][i] == 54) {
            ++counterHigh;
        }
        if (array[2][i] <= 32) {
            ++counterLow;
        }
    }
    cout <<"The number of days the high was 54 degrees was: " << counterHigh <<endl;
    cout << endl;
    cout <<"The number of days the low was below freezing: " << counterLow <<endl;
    cout << endl;
}
