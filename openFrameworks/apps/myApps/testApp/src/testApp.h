#pragma once

#include "ofMain.h"
#include "Player.h"
#include "bullets.h"
#include "Enemy.h"
#include "LevelController.h"
#include "Obstacles.h"



class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    /*-----------------Images Characters--------------------*/
    ofImage player_image;
    ofImage enemy_bullet_image;
    ofImage player_bullet_image;
    ofImage enemy;
    ofImage enemyEx;
    ofImage obstacleImage;
    /*-----------------Images Characters--------------------*/
    
    
        ofVec2f bgPos;
    
    
        string game_state;
        int score;
        Player player_1;
		
     /*---------game look and feel--------*/
    ofImage starbckgd;
    ofImage startScreen;
    ofImage endScreen;
    ofSoundPlayer endSound; 
    ofSoundPlayer playerShoot;
    ofSoundPlayer spaceMusic;
    ofSoundPlayer playerHit;
    ofSoundPlayer playerLostLife; 
    ofTrueTypeFont font; 
    /*--------- game look and feel--------*/
    
    vector<bullet> bullets;
    vector<Enemy> enemies;
    vector<Obstacles> obstacles; 
    
    float maxEnemyAmplitude;
    float maxEnemyShootInterval;
    
    
    
    
    LevelController level_controller;
    void update_bullet();
    void checkBulletCollisions();
    void checkObstacleCollision();
    void draw_lives();
    void draw_score();
    
    
};
