#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    ofHideCursor();
    ofBackground(21);
    radius=30;
    dir=300;
    angle=0;
}

//--------------------------------------------------------------
void ofApp::update(){
    location=ofVec2f(ofGetWidth()/2+dir*cos(angle),ofGetHeight()/2+dir*sin(angle));
    angle+=0.05;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(127);
    ofDrawLine(ofGetWidth()/2, ofGetHeight()/2, location.x, location.y);
    ofSetColor(255);
    ofDrawCircle(location.x, location.y, radius);
}

//--------------------------------------------------------------
