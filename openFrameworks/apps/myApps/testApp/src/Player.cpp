//
//  Player.cpp
//  testApp
//
//  Created by Kyleen Gonzalez on 5/19/17.
//
//

#include <stdio.h>
#include <Player.h>


void Player::setup(ofImage * _img) {
    lives = 3;
    
    speed = 5;
    
    img = _img;
    width = height = img->getWidth();
    
    pos.x = ofGetWidth();//ofGetWidth()/4
    pos.y = ofGetHeight() - height;
    
}

void Player::update() {
    calculate_movement();
    
    
}

void Player::draw() {
    img->draw(pos.x - width, pos.y - height);//pos.x - width/4, pos.y - height/4
    
}

void Player::calculate_movement() {
    if (is_left_pressed && pos.x > 0 + width/2) {
        pos.x -= speed;
    }
    if (is_right_pressed && pos.x < ofGetWidth() - width/2) {
        pos.x += speed;
    }
}
