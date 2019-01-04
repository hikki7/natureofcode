#include "ofApp.h"

using namespace glm;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    ofBackground(0);
    ofHideCursor();
    path=new Path();
    v=new vehicle(vec2(0,ofGetHeight()/2),3,0.05);
}

//--------------------------------------------------------------
void ofApp::update(){
    v->follow(*path);
    v->update();
    v->border(*path);
}

//--------------------------------------------------------------
void ofApp::draw(){
    path->display();
    v->display();
}

