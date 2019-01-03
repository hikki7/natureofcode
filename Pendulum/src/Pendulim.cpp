//
//  Pendulim.cpp
//  Pendulum
//
//  Created by 引田祐樹 on 2018/12/07.
//

#include "Pendulim.hpp"

Pendulim::Pendulim(ofVec2f _origin,float _r){
    origin=_origin;
    r=_r;
    angle=PI/4;
    aVelocity=0;
    damping=0.995;
    rBall=30;
    dragging=false;
}

void Pendulim::update(){
    
    if(!dragging){
        float gravity=0.4;
        aAcceleration=(-1*gravity/r)*sin(angle);
        aVelocity+=aAcceleration;
        aVelocity*damping;
        angle+=aVelocity;
    }
}

void Pendulim::display(){
    location=ofVec2f(r*sin(angle),r*cos(angle));
    location+=origin;
    ofSetColor(127);
    ofDrawLine(origin.x, origin.y, location.x, location.y);
    if(dragging){
        ofSetColor(255);
    }
    ofDrawCircle(location.x, location.y, rBall);
}

void Pendulim::clicked(float _mx,float _my){
    ofVec2f m=ofVec2f(_mx,_my);
    float dist=ofDist(location.x, location.y, m.x, m.y);
    if(dist<rBall){
        dragging=true;
    }
}

void Pendulim::stopDragging(){
    if(dragging){
        aVelocity=0;
        dragging=false;
    }
}

void Pendulim::drag(){
    if(dragging){
        ofVec2f diff=origin-ofVec2f(ofGetMouseX(),ofGetMouseY());
        angle=atan2(-diff.y, diff.x)-PI/2;
    }
}
