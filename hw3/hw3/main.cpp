//
//  main.cpp
//  hw3
//
//  Created by Kyleen Gonzalez on 4/19/17.
//  Copyright © 2017 Kyleen Gonzalez. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Header.h"


using namespace std;


int main() {
    int tempDay[rows][columns];

    /* Code to read in txt file */
    ifstream infile;
    infile.open("weather.txt");
    
    if (!infile) {
        cerr << "Unable to open file  C\n";
        exit(1);   // call system to stop
    }
    /* end code read text file */
    
    /* FIlling 2d array with data from text file */
    for (int i = 0; i < columns; ++i) {
        for (int j = 0; j < rows ; ++j) {
            if (!(infile >> tempDay[j][i])) {
                cerr << "Unexpected end of file\n" << endl;
                exit(1);   // call system to stop
            }
        }
    }
    /* End filling array with data */
    
    //Calling functions for average daily high and average daily low
    averageHighLow(tempDay);
    
    //Calling functions for lowest high temperature and highest low temperature
    cout << endl;
    lowestHigh(tempDay);
    cout << endl;
    highestLow(tempDay);
    cout << endl;
    
    //Calling functions for number of days High was 54 and low was below freezing
    countHighLow(tempDay); 
    
    infile.close();

    
    return 0;
    
}
