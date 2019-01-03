#include "ofApp.h"

void ofApp::pointerExamle(int *pValue,int size){
    for(int i=0;i<size;i++){
        *(pValue+i)*=2;
        cout<<*(pValue+i)<<endl;
    }
}

//--------------------------------------------------------------
void ofApp::setup(){

    int a=0;
    
    int* pPointer;
    
    pPointer = &a;
    
    cout<< a <<*pPointer<<endl;
    a=2;
    cout<< a <<*pPointer<<endl;

    
    int array[]={1,2,3};
    
    pointerExamle(array,3);
    
}



//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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
