#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    ofHideCursor();
    ofBackground(21);
    angle=0;
    aVelocity=0;
    aAcceleration=0.01;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateDeg(angle);
    ofSetColor(255);
    ofDrawCircle(100, 0, 20);
    ofDrawCircle(-100, 0, 20);
    ofSetColor(144);
    ofDrawLine(100, 0, -100, 0);
    
    aVelocity+=aAcceleration;
    angle+=aVelocity;
}

//--------------------------------------------------------------
