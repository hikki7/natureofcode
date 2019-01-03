//
//  Mover.cpp
//  aVelocityAttractor
//
//  Created by 引田祐樹 on 2018/12/05.
//

#include "Mover.hpp"

Mover::Mover(float _m,float _x,float _y){
    m=_m;
    location=ofVec2f(_x,_y);
    velocity=ofVec2f(ofRandom(-ofGetWidth(),ofGetWidth()),ofRandom(-ofGetHeight(),ofGetHeight()));
    velocity.normalize();
    acceleration=ofVec2f(0,0);
    
    aAcceleration=0;
    aVelocity=0;
    angle=0;
}

void Mover::addForce(ofVec2f _force){
    ofVec2f force=_force/m;
    acceleration+=force;
}

void Mover::update(){
    velocity+=acceleration;
    location+=velocity;
    aAcceleration=acceleration.x;
    aVelocity+=aAcceleration;
    
    if(aVelocity<-10){
        aVelocity=-10;
    }else if(aVelocity>10){
        aVelocity=10;
    }
    
    angle+=aVelocity;
    acceleration*=0;
    cout<<angle<<endl;
}

void Mover::display(){
    OF_RECTMODE_CENTER;
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofRotateDeg(angle);
    ofSetColor(255);
    ofDrawRectangle(0, 0, m*10, m*10);
    ofPopMatrix();
}
