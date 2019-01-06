#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetFullscreen(true);
    ofBackground(0);
    
    for(int i=0;i<firstNum;i++){
        auto b=make_unique<Boid>(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
        boids.push_back(move(b));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(auto& b: boids){
        b->flock(boids);
        b->update();
        b->borders();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(auto& b: boids){
        b->display();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    auto b=make_unique<Boid>(float(x),float(y));
    boids.push_back(move(b));
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
