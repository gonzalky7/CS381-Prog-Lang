//
//  LevelController.cpp
//  testApp
//
//  Created by Kyleen Gonzalez on 6/3/17.
//
//

#include <stdio.h>
#include "LevelController.h"

void LevelController::setup(float s) {
    start_time = s;
    interval_time = 500; //how often enemies will spawn
}
bool LevelController::should_spawn() {
    if (ofGetElapsedTimeMillis() - start_time > interval_time) {
        start_time = ofGetElapsedTimeMillis();
        return true;
    }

    return false;
}
