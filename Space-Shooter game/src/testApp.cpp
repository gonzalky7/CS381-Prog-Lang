#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    /*--------look and feel------------*/
    game_state = "start";
    starbckgd.load("star.jpeg");
    startScreen.load("spaceStart.jpg");
    endScreen.load("endScreen.jpg");
    spaceMusic.load("spaceinvaders1.mpeg");
    endSound.load("gameOver.mp3");
    font.load("font.otf", 48);
    
    
    /* ------------enemy/player----------*/
    player_image.load("player.png");
    player_1.setup(&player_image);
    playerShoot.load("7.wav"); //sound of player shooting
    playerHit.load("playerHit.wav");
    playerLostLife.load("Hero_Death_00.wav");
    player_bullet_image.load("player_bullet.png");
    
    enemy_bullet_image.load("enemy_bullet.png");
    enemy.load("aliensprite2.png");
    enemyEx.load("enemyExplosion.jpg");
    maxEnemyAmplitude = 3.5;//movement from left to right oscillation factor
    maxEnemyShootInterval = 1.5;
    obstacleImage.load("obstacle.png");
    
    for(int i = 0; i < 2; i++){
    Enemy e;							// create the enemy object
    e.setup(maxEnemyAmplitude,maxEnemyShootInterval, &enemy);	// setup its initial state, fill vector
    enemies.push_back(e);
    }
    
        Obstacles ob;
        ob.setup(&obstacleImage);
        obstacles.push_back(ob);
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    if (game_state == "start") {
        
        
    } else if (game_state == "game") {
        
        player_1.update();
        update_bullet();
                
        for (int i = 0; i < enemies.size(); i++) {//vector<Enemy> enemies; enemies.size == 1
            
            enemies[i].update();
            if (enemies[i].timeToShoot()) {
                bullet bs;
                bs.setup(false, enemies[i].pos, enemies[i].speed, &enemy_bullet_image);
                bullets.push_back(bs);
            }
            
            if (level_controller.should_spawn() == true) {
                Enemy e;
                e.setup(maxEnemyAmplitude, maxEnemyShootInterval, &enemy);
                enemies.push_back(e);
            }
              if(enemies[i].pos.y > ofGetHeight() + 50){ //erases enemies once off screen keep vector small stops slowing down of game
              enemies.erase(enemies.begin() + i);
              }
            if (enemies[i].pos.x > ofGetWidth() + 50) {
                enemies.erase(enemies.begin() + i);
            }
            
            
        }
        
        checkObstacleCollision();
    }
    
    
}
//--------------------------------------------------------------
void testApp::draw(){
    if (game_state == "start") {
        startScreen.draw(0,0,ofGetWidth(), ofGetHeight());
        spaceMusic.play();
        //obstacleImage.draw(100, ofGetHeight()-100); //x,y 0,0 top left corner
        


    } else if (game_state == "game") {
                starbckgd.draw(0,0,ofGetWidth(), ofGetHeight());
        
        player_1.draw(); //need to draw after background is called
        
        draw_lives();
        draw_score();
        
        /*-----------testing values-----------------------*/
                ofSetColor(ofColor::white);
        ofSetColor(ofColor::white);
        ofDrawBitmapString("Turn off music: press m ", 10, 10);
        
        
        ofSetColor(ofColor::white);
         ofDrawBitmapString("obstacle vector size: " + ofToString(obstacles.size()), 200, 10);
        
        ofSetColor(ofColor::white);
        ofDrawBitmapString("enemies vector size: " + ofToString(enemies.size()), 400, 10);
        
        ofSetColor(ofColor::white);
        ofDrawBitmapString("height: " + ofToString(ofGetHeight()), 800, 10);
        
        for (int i = 0; i < obstacles.size(); i++) {
            ofSetColor(ofColor::white);
            ofDrawBitmapString("obstacles: " + ofToString(obstacles[i].pos.y), 600, 10);
        }
        
        /*-----------testing values-----------------------*/

        for (int i = 0; i < enemies.size(); i++) {
            enemies[i].draw();
        }
        
        for (int i = 0; i < bullets.size(); i++) {
            bullets[i].draw();
        }
        
        for (int i = 0; i < obstacles.size(); i++){
            obstacles[i].draw(); 
        }
        
    } else if (game_state == "end") {
        endScreen.draw(0,0,ofGetWidth(), ofGetHeight());
        
        
    }
   

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (game_state == "game") {
        if (key == OF_KEY_LEFT) {
            player_1.is_left_pressed = true;
        }
        
        if (key == OF_KEY_RIGHT) {
            player_1.is_right_pressed = true;
        }
        
        
        if (key == ' ') {
            bullet b;
            b.setup(b.straightShot = true, player_1.pos, player_1.speed, &player_bullet_image);
            playerShoot.play();
            bullets.push_back(b);
        }
        if (key == 'b') {
            bullet bz;
            bz.setup(bz.rightSideShot = true, player_1.pos, player_1.speed, &player_bullet_image);
            playerShoot.play();
            bullets.push_back(bz);
        }
        if (key == 'v') {
            bullet bu;
            bu.setup(bu.leftSideShot = true, player_1.pos, player_1.speed, &player_bullet_image);
            playerShoot.play();
            bullets.push_back(bu);
        }
        
        if (key == 'm'){
            spaceMusic.stop();
        }
        
    }


}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if (game_state == "start") {
        game_state = "game";
        level_controller.setup(ofGetElapsedTimeMillis());
    } else if (game_state == "game") {
        
        if (key == OF_KEY_LEFT) {
            player_1.is_left_pressed = false;
            
        }
        
        if (key == OF_KEY_RIGHT) {
            player_1.is_right_pressed = false;
        }
        
    }
}
//--------------------------------------------------------------
void testApp::update_bullet() {
    for (int i = 0; i < bullets.size(); i++) {
        bullets[i].update();
        
    }
    
    checkBulletCollisions();
}

/*
for loop i is less than bullets.size increase i {
 if bullets[i] (vector<bullet> bullets) are from player {
 
 }
 
 }
 
 


*/
//--------------------------------------------------------------
void testApp::checkBulletCollisions() {
    
    for (int i = 0; i < bullets.size(); i++) {
            if (bullets[i].straightShot || bullets[i].rightSideShot || bullets[i].leftSideShot) {
           
                for (int e = enemies.size(); e >= 0; e--) {
                    if (ofDist(bullets[i].pos.x, bullets[i].pos.y, enemies[e].pos.x, enemies[e].pos.y) <(enemies[e].width + bullets[i].width)/2) {
                        playerHit.play();
                        enemies.erase(enemies.begin()+e);

                        bullets.erase(bullets.begin()+i);//bullets.erase(bullets.begin()+i)
                        score+=10;
                    }
                }
                
                /* ----------------- Obstacle Logic------------------------------*/
                for (int ob = obstacles.size(); ob >= 0; ob--) {
                    if (ofDist(bullets[i].pos.x, bullets[i].pos.y, obstacles[ob].pos.x, obstacles[ob].pos.y) < (obstacles[ob].width + bullets[i].width)/2) {
                        playerHit.play();
                        obstacles.erase(obstacles.begin()+ob);//particles.erase( particles.begin() + 3 ); // erase third element n element
                        bullets.erase(bullets.begin()+i);
                        
                        Obstacles ob;
                        ob.setup( &obstacleImage);
                        obstacles.push_back(ob);
                    }
                    
                }
            }else if (ofDist(bullets[i].pos.x, bullets[i].pos.y, player_1.pos.x, player_1.pos.y) < (bullets[i].width+player_1.width)/2) {
                playerLostLife.play();
                bullets.erase(bullets.begin()+i);
                player_1.lives--;
                
                if (player_1.lives <= 0) {
                    game_state = "end";
                    endSound.play();
                    spaceMusic.stop();
                }
            }
    }
}
//-------------------------------------------------------------
void testApp::checkObstacleCollision(){
    
    for (int ob = 0; ob < obstacles.size(); ob++) {
        if (ofDist(obstacles[ob].pos.x, obstacles[ob].pos.y, player_1.pos.x, player_1.pos.y) < (obstacles[ob].width + player_1.width)/2) {
            playerLostLife.play(); 
            obstacles.erase(obstacles.begin()+ob);//particles.erase( particles.begin() + 3 ); // erase third element n element
            player_1.lives--;
            
            Obstacles o;
            o.setup( &obstacleImage);
            obstacles.push_back(o);
            
            if (player_1.lives <= 0) {
                game_state = "end";
                endSound.play();
                spaceMusic.stop();
            }
            
        }
    }
}
//-------------------------------------------------------------
void testApp::draw_lives() {
    for (int i = 0; i < player_1.lives; i++) {
        player_image.draw(ofGetWidth() - (i * player_image.getWidth()) - 100, 30);
    }
}
//--------------------------------------------------------------
void testApp::draw_score() {
    if (game_state == "game") {
        font.drawString(ofToString(score), 30, 72);
    } else if (game_state == "end") {
        float w = font.stringWidth(ofToString(score));
        font.drawString(ofToString(score), ofGetWidth()/2 - w/2, ofGetHeight()/2 + 100);
    }
}
//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
