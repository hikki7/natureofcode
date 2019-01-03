#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    ofBackground(21);
    p=new Pendulim(ofVec2f(ofGetWidth()/2,0),ofGetHeight()/2);
}

//--------------------------------------------------------------
void ofApp::update(){
    p->drag();
    p->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    p->display();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    p->clicked(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    p->stopDragging();
}

