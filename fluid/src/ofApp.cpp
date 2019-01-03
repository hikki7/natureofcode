#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetWindowShape(1280, 720);
    fluidSimulation.setup(ofGetWidth()/4, ofGetHeight()/4);
    fluidSimulation.setDissipation(0.0);
    mouseForces.setup(ofGetWidth()/4, ofGetHeight()/4,ofGetWidth(),ofGetHeight());
    lastTime = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::update(){
    deltaTime = ofGetElapsedTimef()-lastTime;
    lastTime = ofGetElapsedTimef();
    mouseForces.update(deltaTime);
    
    for (int i = 0; i<mouseForces.getNumForces(); i++) {
        if(mouseForces.didChange(i)){
            fluidSimulation.addDensity(mouseForces.getTextureReference(i),mouseForces.getStrength(i));
            fluidSimulation.addVelocity(mouseForces.getTextureReference(i),mouseForces.getStrength(i));
        }
    }
    fluidSimulation.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    fluidSimulation.draw(0,0,1280,720);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == 'c'){
        fluidSimulation.reset();
        }
}
