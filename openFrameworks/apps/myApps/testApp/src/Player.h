//
//  Player.h
//  testApp
//
//  Created by Kyleen Gonzalez on 5/19/17.
//
//
#include "ofMain.h"

#ifndef Player_h
#define Player_h

#pragma once


class Player {
public:
    ofPoint pos; 
    float width, height, speed;
    int lives;
    
    bool is_left_pressed, is_right_pressed;
    
    void setup(ofImage * _img);
    void update();
    void draw();
    void shoot();
    
    void calculate_movement();
    
    bool check_can_shoot();
    
    ofImage * img;
    
};
#endif /* Player_h */
