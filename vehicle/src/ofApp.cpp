#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFullscreen(true);
    ofSetCircleResolution(64);
    ofBackground(0);
    
    mouse=ofVec2f(ofGetWidth(),ofGetHeight());
    radius=30;
    
    v=new vehicle();
}

//--------------------------------------------------------------
void ofApp::update(){
    mouse=ofVec2f(ofGetMouseX(),ofGetMouseY());
    v->seek(mouse);
    v->update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(255,127);
    ofDrawCircle(mouse, radius);
    
    v->display();
}

