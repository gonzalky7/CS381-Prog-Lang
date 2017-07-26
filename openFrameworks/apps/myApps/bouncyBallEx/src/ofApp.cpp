#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    myBall.setup(); // calling the object's setup method
    myBall1.setup();
    myBall2.setup();
    myBall3.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    myBall.update(); // calling the object's update method
    myBall1.update();
    myBall2.update();
    myBall3.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    myBall.draw(); // call the draw method to draw the object
    myBall1.draw();
    myBall2.draw();
    myBall3.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
