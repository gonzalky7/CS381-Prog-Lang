//
//  main.cpp
//  PracticeKeepDammit
//
//  Created by Kyleen Gonzalez on 4/30/17.
//  Copyright © 2017 Kyleen Gonzalez. All rights reserved.
//

#include "Header.h"

char arr[5][5][5];
using namespace std;


int main() {
    int turn = 0;
    int counterCats = 0;

    
    string input;
    int grid, row, col;
    resetARRAY(arr);
    
    while (true) {
        turn++;
        DISPLAY(arr);
        
        if (turn%2==0) {cout<<"\nPlayer O, it's your turn!\n\n";}
        else {cout<<"\nPlayer X, it's your turn!\n\n";}

        
        do {
            cout<<"Enter Board #: ";
            cin >> grid;
            checkRowInput(grid);
        } while (checkGridInput(grid) == false);
        
        
        cout<<"Row number :  ";
        cin >> row;
        
        while (checkRowInput(row) == false) {
            cout<<"Enter valid Row #: ";
            cin >> row;
            //checkRowInput(row);
        }

        cout <<"Column number: ";
        cin >> col;
        
        while (checkRowInput(col) == false) {
            cout<<"Enter valid Column #: ";
            cin >> col;
            //checkRowInput(col);
        }

        while (arr[grid][row][col] =='O' || arr[grid][row][col] =='X') {
            cout << "Please select unoccupied space"<<endl;
            cout << "Enter valid Row: " <<endl;
            cin >>row;
            cout << "Enter valid Column: " <<endl;
            cin >>col;
        }
        
        
        if (turn%2==0) {arr[grid][row][col]='O';}
        else {arr[grid][row][col]='X';}
    
        ++counterCats; 
        checkWINNER(turn, arr, counterCats);
    }

    return 0;
}



