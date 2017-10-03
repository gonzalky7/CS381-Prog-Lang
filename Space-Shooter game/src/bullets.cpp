//
//  bullets.cpp
//  testApp
//
//  Created by Kyleen Gonzalez on 5/25/17.
//
//

#include <stdio.h>
#include "bullets.h"


void bullet::setup(bool fromPlayer, ofPoint p, float s, ofImage * bulletImage) {
    pos = p;
    speed = s + 3;
    img = bulletImage;
    width = img->getWidth(); //getWitdth() returns the width of the image in pixes
       
}
void bullet::update() {
    if (rightSideShot) {
        pos.x += speed;
    }else if(leftSideShot){
        pos.x -= speed;
    }else if (straightShot){
        pos.y -= speed;
    }else {
        pos.y += speed;
    }
    
    

}
void bullet::draw() {
    img->draw(pos.x - width/2, pos.y - width/2);
     
}





