//
//  Mover.cpp
//  pointting_velocity
//
//  Created by 引田祐樹 on 2018/12/06.
//

#include "Mover.hpp"

Mover::Mover(){
    location=ofVec2f(ofGetWidth()/2,ofGetHeight()/2);
    velocity=ofVec2f(0,0);
    acceleration=ofVec2f(0,0);
    topSpeed=4;
    r=30;
}

void Mover::update(){
    ofVec2f mouse=ofVec2f(ofGetMouseX(),ofGetMouseY());
    ofVec2f dir=mouse-location;
    dir.normalize();
    dir*=0.5;
    acceleration=dir;
    velocity+=acceleration;
    if(velocity.length()>topSpeed){
        velocity.normalize();
        velocity*=topSpeed;
    }
    location+=velocity;
}

void Mover::display(){
    float theta=atan2(velocity.y,velocity.x);
    ofSetColor(255);
    ofPushMatrix();
    ofTranslate(location.x,location.y);
    ofRotateRad(theta);
    ofDrawRectangle(0, 0, r, r);
    ofPopMatrix();
}

void Mover::checkEdge(){
    
    if(location.x>ofGetWidth()){
        location.x=0;
    }else if(location.x<0){
        location.x=ofGetWidth();
    }
    
    if(location.y>ofGetHeight()){
        location.y=0;
    }else if(location.y<0){
        location.y=ofGetHeight();
    }
}
