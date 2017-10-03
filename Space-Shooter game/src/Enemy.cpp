//
//  Enemy.cpp
//  testApp
//
//  Created by Kyleen Gonzalez on 6/3/17.
//
//

#include <stdio.h>
#include "Enemy.h"

void Enemy::setup(float maxEnemyAmplitude, float maxEnemyShootInterval, ofImage * enemy_image) {
    pos.x = ofRandom(ofGetWidth());
    pos.y = 0;
    img = enemy_image;
    width = img->getWidth();
    
    speed = ofRandom(2, 8);
    amplitude = ofRandom(maxEnemyAmplitude);
    shoot_interval = ofRandom(0.5, maxEnemyShootInterval);
    start_shoot = ofGetElapsedTimef();
}
void Enemy::update() {
    pos.y += speed;
    pos.x += amplitude * sin(ofGetElapsedTimef());// moves sinusoidally across the screen
}
void Enemy::draw() {
    img->draw(pos.x - width/2, pos.y - width/2);//pos.x - width/2, pos.y - width/2
}
bool Enemy::timeToShoot() {
    if (ofGetElapsedTimef() - start_shoot > shoot_interval) {
        start_shoot = ofGetElapsedTimef();
        return true;
    }
    return false;
}
