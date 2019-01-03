//
//  Vehicle.cpp
//  FlowField
//
//  Created by 引田祐樹 on 2018/12/18.
//

#include "Vehicle.hpp"

Vehicle::Vehicle(){
    location=ofVec2f(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
    velocity=ofVec2f(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
    velocity.normalize();
    acceleration=ofVec2f(0,0);
    hue=ofRandom(255);
    col.setHsb(hue, 255, 255);
    r=10;
    maxSpeed=ofRandom(2,5);
    maxForce=ofRandom(0.1,0.5);
    
}

void Vehicle::update(){
    velocity+=acceleration;
    location+=velocity;
    acceleration*=0;
}

void Vehicle::addForce(ofVec2f _force){
    ofVec2f force=_force;
    acceleration+=force;
    return acceleration;
}

void Vehicle::display(){
    
    float theta=atan2(location.y,location.x);
    
    ofSetColor(col);
    ofPushMatrix();
    ofTranslate(location.x,location.y);
    ofRotateRad(theta);
    ofDrawTriangle(location.x,location.y-r*cos(PI/3),location.x-r*sin(PI/3) ,location.y+r*cos(PI/3) ,location.x+r*sin(PI/3) ,location.y+cos(PI/3));
    ofPopMatrix();
}

void Vehicle::follow(ofVec2f _desired){
    ofVec2f desired=_desired;
    desired*=maxSpeed;
    
    ofVec2f steer=desired-velocity;
    
    if(steer.length()>maxForce){
        steer.normalize();
        steer*=maxForce;
    }
    
    addForce(steer);
}

void Vehicle::border(){
    if(location.x>ofGetWidth()+r){
        location.x=-r;
    }
    if(location.x<-r){
        location.x=ofGetWidth()+r;
    }
    
    if(location.y>ofGetHeight()+r){
        location.y=-r;
    }
    if(location.y<-r){
        location.y=ofGetHeight()+r;
    }
}



