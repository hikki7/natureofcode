#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    ofBackground(0);
    mover=new Mover();
}

//--------------------------------------------------------------
void ofApp::update(){
    mover->update();
    mover->checkEdge();
}

//--------------------------------------------------------------
void ofApp::draw(){
    mover->display();
}

