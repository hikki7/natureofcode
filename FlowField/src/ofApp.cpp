#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    //ofHideCursor();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofBackground(0);
    
    ff=new FlowField();
    
    for(int i=0;i<num;i++){
        vehicle[i]=new Vehicle();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0;i<num;i++){
        ofVec2f desired=ff->lookup(vehicle[i]->location);
        vehicle[i]->follow(desired);
        vehicle[i]->border();
        vehicle[i]->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ff->display();
    for (int i=0; i<num; i++) {
        vehicle[i]->display();
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ff->init();
}
