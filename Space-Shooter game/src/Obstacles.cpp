//
//  Obstacles.cpp
//  testApp
//
//  Created by Kyleen Gonzalez on 6/13/17.
//
//

#include <stdio.h>
#include "Obstacles.h"


void Obstacles::setup (ofImage * obstacleImage) {
    //pos.x = ofRandom(ofGetWidth());//obstacleImage.draw(100, ofGetHeight()-100); //x,y 0,0 top left corner
    //pos.y = ofGetHeight() - 100 ;
    img = obstacleImage;
    width = height = img->getWidth();
    
    pos.x = ofRandom(ofGetWidth());//ofGetWidth()/4
    pos.y = ofGetHeight() - height;
}
/*void Obstacles::update() {
    }*/

void Obstacles::draw() {
    img->draw(pos.x, pos.y);
}
