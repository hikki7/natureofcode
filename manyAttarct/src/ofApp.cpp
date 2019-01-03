#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    ofBackground(21);
    ofHideCursor();
    
    for(int i=0;i<num;i++){
        float x=ofRandom(ofGetWidth());
        float y=ofRandom(ofGetHeight());
        float mass=ofRandom(1,2);
        ball[i]=new Ball(&x, &y, &mass);
        
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i=0;i<num;i++){
        for (int j=0; j<num; j++) {
            if(i!=j){
                ofVec2f force=ball[j]->attract(ball[i]);
                ball[i]->addForce(force);
            }
        }
        ball[i]->update();
        ball[i]->checkBound();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<num; i++) {
        ball[i]->display();
    }
}

