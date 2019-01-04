#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    ofBackground(0);
    
    for(int i=0;i<100;i++){
        auto v=make_unique<vehicle>(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
        this->vehicles.push_back(move(v));
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (auto& v : vehicles) {
        v->applyBehaviors(vehicles);
        v->update();
        v->borders();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (auto& v : vehicles) {
        v->display();
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
    auto v=make_unique<vehicle>(ofGetMouseX(),ofGetMouseY());
    this->vehicles.push_back(move(v));}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
