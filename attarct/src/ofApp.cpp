#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    //ofHideCursor();
    ofBackground(21);
    
    for(int i=0;i<num;i++){
        mover[i]=new Mover(ofRandom(1,5),ofVec2f(ofRandom(ofGetWidth()),ofRandom(ofGetHeight())));
    }
    a=new Attractor();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<num; i++) {
        ofVec2f force=a->attract(mover[i]);
        mover[i]->addForce(force);
        mover[i]->update();
    }
    
    
    a->drag();
    a->hover(ofGetMouseX(), ofGetMouseY());
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    a->display();
    for (int i=0; i<num; i++) {
        mover[i]->display();
    }
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    a->clicked(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    a->stopDragging();
}
