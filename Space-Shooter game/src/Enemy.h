//
//  Enemy.h
//  testApp
//
//  Created by Kyleen Gonzalez on 6/3/17.
//
//
#include "ofMain.h"
#pragma once
#ifndef Enemy_h
#define Enemy_h

class Enemy {
public:
    ofPoint pos;
    float speed;
    float amplitude;
    float width;
    
    float start_shoot;
    float shoot_interval;
    
    void setup(float maxEnemyAmplitude, float maxEnemyShootInterval, ofImage * enemy_image);
    void update();
    void draw();
    bool timeToShoot();
    
    ofImage * img;
};

#endif /* Enemy_h */
