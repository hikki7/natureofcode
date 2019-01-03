#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    ofBackground(21);
    ofHideCursor();
    ofSetCircleResolution(64);
    for(int i=0;i<num;i++){
        mover[i] = new Mover(ofRandom(0.1,2.0),ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
    }
    
    attract=new Attractor();
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0;i<num;i++){
        ofVec2f force=attract->attract(mover[i]);
        mover[i]->addForce(force);
        mover[i]->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    attract->display();
    
    for(int i=0;i<num;i++){
        mover[i]->display();
    }
}

//--------------------------------------------------------------
