#pragma once///Users/Kyleen/Desktop/openFrameworks/apps/myApps/mySoftSketch/src/ofApp.cpp

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    ofImage image;
    ofTrueTypeFont myFont; 
};

