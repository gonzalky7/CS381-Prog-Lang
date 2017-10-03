//
//  functions.cpp
//  PracticeKeepDammit
//
//  Created by Kyleen Gonzalez on 4/30/17.
//  Copyright © 2017 Kyleen Gonzalez. All rights reserved.
//

#include "Header.h"

//int counterCats = 0;


char player;
using namespace std;

void DISPLAY (char brd[][5][5]){
    for(int i=1;i<5;i++)
    {
        cout << "Board # "<< i << endl;
        cout <<" "<< " 1 "<<"  2 "<<"  3 "<<"  4 " << endl;
        for(int j=1;j<=4;j++)
        {
            cout << j;
            for(int k=1;k<=4;k++)
            {
                cout <<" " << brd[i][j][k]<< "  ";
                
            }
            printf("\n\n");
        }
        //printf("\n");
        
    }
  
}

void resetARRAY (char brd[][5][5]) {
    for (int x=1;x<5;x++) {
        for (int y=1;y<6;y++) {
            for (int z=1;z<6;z++) {
                brd[x][y][z]= '-';
            }
        }
    }
}

void checkWINNER (int turn, char brd[][5][5], int counter){
    int counterCats = counter;
    
    if (turn %2 == 0) {
        player = 'O';
    }else player= 'X';
    
for (int g = 1; g < 5; ++g) {
    for (int r = 1; r < 5; ++r) {
        
//checking for Horizontal wins for each board
if (player == brd[g][r][1] && player ==brd[g][r][2] && player ==brd[g][r][3] && player ==brd[g][r][4]) {displayWINNER(turn, brd);}
     
//checking for Vertical wins for each board
if (player == brd[g][1][r] && player ==brd[g][2][r] && player ==brd[g][3][r] && player ==brd[g][4][r]) {displayWINNER(turn, brd);}
      
//checking for Diagonal wins for each board
if (player == brd[g][1][r] && player ==brd[g][2][2] && player ==brd[g][3][3] && player ==brd[g][4][4]) {displayWINNER(turn, brd);}

//checking for Diagonal wins for each board
if (player == brd[g][4][1] && player ==brd[g][3][2] && player ==brd[g][2][3] && player ==brd[g][1][4]) {displayWINNER(turn, brd);}
    }
}
        /*-----------------Checking for 3 dimensional wins -----------*/
for (int rows = 1; rows < 5; ++ rows) {
    for (int col = 1; col < 5; ++col) {
        
//checking for Horizontal wins for each board
if (player == brd[1][rows][col] && player ==brd[2][rows][col] && player ==brd[3][rows][col] && player ==brd[4][rows][col]) {displayWINNER(turn, brd);}
        
//checking for Diagonal wins for each board
if (player == brd[1][1][1] && player ==brd[2][2][2] && player ==brd[3][3][3] && player == brd[4][4][4]) {displayWINNER(turn, brd);}
        
if (player == brd[1][4][4] && player ==brd[2][3][3] && player ==brd[3][2][2] && player == brd[4][1][1]) {displayWINNER(turn, brd);}
        
//checking for Diagonal wins for each board
if (player == brd[1][1][4] && player ==brd[2][2][3] && player ==brd[3][3][2] && player ==brd[4][4][1]) {displayWINNER(turn, brd);}
        
if (player == brd[4][1][4] && player ==brd[3][2][3] && player ==brd[2][3][2] && player ==brd[1][4][1]) {displayWINNER(turn, brd);}
        
    }
}
    /*-----------------Checking for draw  -----------*/
    if (counterCats == 64) {
        cout << endl;
        cout << "Cats game no winner so sad!!" <<endl;
        exit(1);
    }
    
    cout <<"Counter for cats game: " << counterCats <<endl;
  
}//ench of function bracket


bool displayWINNER(int turn, char brd[][5][5]){

    if (turn%2==0) {cout<<"\n\nO is the winner!!\n\n";}
    else cout<<"\n\nX is the winner!!\n\n";
    DISPLAY(brd);
         exit(1);

}


bool checkGridInput(int input){
    if(cin.fail()) {
        cin.clear();
        cin.ignore(256,'\n');
        return false;
    } else if ( (input < 1) || (input > 4)){
        return false;
    }
    return true;
}

bool checkRowInput(int input){
    
    if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    } else if ((input < 0) || (input > 4)){
        return false; 
       }
    return true;
}

    
    








