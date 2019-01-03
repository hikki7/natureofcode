//
//  vehicle.cpp
//  vehicle
//
//  Created by 引田祐樹 on 2018/12/14.
//

#include "vehicle.hpp"


vehicle::vehicle(){
    location=ofVec2f(ofRandom(ofGetWidth()/2),ofRandom(ofGetHeight()/2));
    velocity=ofVec2f(0,-2);
    acceleration=ofVec2f(0,0);
    r=10;
    maxSpeed=4;
    maxForce=0.1;
}

void vehicle::update(){
    
    velocity+=acceleration;
    
    if(velocity.length()>maxSpeed){
        velocity.normalize();
        velocity*=maxSpeed;
    }
    
    location+=velocity;
    acceleration*=0;
    
}

void vehicle::display(){
    float theta=atan2(velocity.y, velocity.x)+PI/2;
    ofSetColor(255);
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofRotateRad(theta);
    ofDrawTriangle(0, -r, -cos(PI/3)*r,sin(PI/3)*r,cos(PI/3)*r,sin(PI/3)*r);
    ofPushMatrix();
}

void vehicle::addForce(ofVec2f _force){
    acceleration+=_force;
}

void vehicle::seek(ofVec2f _target){
    ofVec2f desired=_target-location;
    
    float d=desired.length();
    desired.normalize();
    
    if(d<100){
        float m=ofMap(d, 0, 100, 0, maxSpeed);
        desired*=m;
    }else{
        desired*=maxSpeed;
    }
    
    ofVec2f steer=desired-velocity;

    if(steer.length()>maxForce){
        steer.normalize();
        steer*=maxForce;
    }
    
    addForce(steer);
}


