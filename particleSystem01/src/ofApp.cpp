#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    //ofHideCursor();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofBackground(0);
    gravity=ofVec2f(0,0.1);
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=ps.size()-1;i>=0;i--){
        particleSystem* p=ps[i];
        p->addForce(gravity);
        p->createParticle();
        p->control();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=ps.size()-1; i>=0; i--) {
        particleSystem* p=ps[i];
        p->drawParticle();
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ps.push_back(new particleSystem(ofVec2f(x,y)));
}
