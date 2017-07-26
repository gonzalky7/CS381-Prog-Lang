#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image.load("images.jpeg");
    myFont.load("VoiceoftheHighlander.ttf", 90);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
   
    image.draw(ofGetMouseX()- 100, ofGetMouseY()-100);
    
    ofSetColor(0, 255, 0); 
    ofDrawBitmapString("Hello back", 300, 300);
    
    ofSetColor(255, 0, 0);
    ofDrawRectangle(100, 100, 100, 100);
    
    ofSetColor(0, 0, 255);
    
    ofDrawRectRounded(200, 200, 100, 100, 10);
}

