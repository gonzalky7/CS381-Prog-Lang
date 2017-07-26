//
//  bullets.h
//  testApp
//
//  Created by Kyleen Gonzalez on 5/25/17.
//
//
#include "ofMain.h"

#ifndef bullets_h
#define bullets_h

class bullet {
public:
    ofPoint pos;
    float speed;
    float width;
   
    bool straightShot, rightSideShot, leftSideShot;
    
    void setup(bool fromPlayer, ofPoint p, float s, ofImage * bulletImage);
    void update();
    void draw();
    
    ofImage * img;
    
};

#endif /* bullets_h */
