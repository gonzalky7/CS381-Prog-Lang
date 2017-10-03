//
//  LevelController.h
//  testApp
//
//  Created by Kyleen Gonzalez on 6/3/17.
//
//
#include "ofMain.h"

#ifndef LevelController_h
#define LevelController_h
class LevelController {
public:
    float start_time;
    float interval_time;
    
    void setup(float e);
    bool should_spawn();
};

#endif /* LevelController_h */
