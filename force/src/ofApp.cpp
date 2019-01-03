#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    ofHideCursor();
    ofBackground(0);
    wind=ofVec2f(0.01,0);
    gravityScale=0.1;
    for(int i=0;i<num;i++){
        ball[i] = new Ball(ofRandom(1,5));
        frictionScale[i]=0.01*ball[i]->mass;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0;i<num;i++){
        ofVec2f gravity=ofVec2f(0,gravityScale*ball[i]->mass);
        ofVec2f friction=ball[i]->velocity;
        friction*=-1;
        friction*=frictionScale[i];
        ball[i]->update();
        ball[i]->addForce(gravity);
        ball[i]->addForce(friction);
        ball[i]->addForce(wind);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0;i<num;i++){
        ball[i]->display();
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
