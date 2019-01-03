#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    ofHideCursor();
    ofBackground(0);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    psys=new particleSystem();
    rp=new repeller();
}

//--------------------------------------------------------------
void ofApp::update(){
    psys->addParticle();
    ofVec2f gravity=ofVec2f(0,0.1);
    psys->addForce(& gravity);
    psys->control();
}

//--------------------------------------------------------------
void ofApp::draw(){
    psys->particleDisplay();
    rp->display();
}


