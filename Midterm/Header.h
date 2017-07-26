//
//  Header.h
//  PracticeKeepDammit
//
//  Created by Kyleen Gonzalez on 4/30/17.
//  Copyright © 2017 Kyleen Gonzalez. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include<limits>



void DISPLAY (char brd[5][5][5]);
void resetARRAY(char brd[5][5][5]);

void checkWINNER (int turn, char brd[5][5][5], int counter);
bool displayWINNER(int turn, char brd[5][5][5]);

bool checkGridInput(int input);
bool checkRowInput(int input);

#endif /* Header_h */
