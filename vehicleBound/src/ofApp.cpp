#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    ofHideCursor();
    ofBackground(0);
    v=new vehicle();
}

//--------------------------------------------------------------
void ofApp::update(){
    v->bounding();
    v->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    v->display();
}

