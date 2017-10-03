//
//  Obstacles.h
//  testApp
//
//  Created by Kyleen Gonzalez on 6/13/17.
//
//

#include "ofMain.h"
#ifndef Obstacles_h
#define Obstacles_h


class Obstacles {
public:
    
    ofPoint pos;
    float width;
    float height; 
   
    
    void setup(ofImage * obstacleImage);
    //void update();
    void draw();
        
    ofImage * img;
};

#endif /* Obstacles_h */
