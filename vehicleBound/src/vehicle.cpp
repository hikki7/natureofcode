//
//  vehicle.cpp
//  vehicleBound
//
//  Created by 引田祐樹 on 2018/12/16.
//

#include "vehicle.hpp"

vehicle::vehicle(){
    location=ofVec2f(ofRandom(ofGetWidth()/2),ofRandom(ofGetHeight()/2));
    velocity=ofVec2f(2,-2);
    acceleration=ofVec2f(0,0);
    r=10;
    maxSpeed=4;
    maxForce=0.1;
    d=25;
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
    
    ofNoFill();
    ofSetColor(255);
    ofDrawRectangle(d, d, ofGetWidth()-2*d, ofGetHeight()-2*d);
    
    float theta=atan2(velocity.y, velocity.x)+PI/2;
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofRotateRad(theta);
    ofDrawTriangle(0, -r, -cos(PI/3)*r,sin(PI/3)*r,cos(PI/3)*r,sin(PI/3)*r);
    ofPushMatrix();
}

void vehicle::addForce(ofVec2f _force){
    acceleration+=_force;
}


void vehicle::bounding(){
    
    ofVec2f steer=ofVec2f(0,0);
    
    if(location.x<5*d){
        ofVec2f desired=ofVec2f(maxSpeed,velocity.y);
        steer=desired-velocity;
        
        if(steer.length()>maxSpeed){
            steer.normalize();
            steer*=maxForce;
        }
    }else if(location.x>ofGetWidth()-5*d){
        ofVec2f desired=ofVec2f(-maxSpeed,velocity.y);
        steer=desired-velocity;
        
        if(steer.length()>maxSpeed){
            steer.normalize();
            steer*=maxForce;
        }
    }else if(location.y<5*d){
        ofVec2f desired=ofVec2f(velocity.x,maxSpeed);
        steer=desired-velocity;
        
        if(steer.length()>maxSpeed){
            steer.normalize();
            steer*=maxForce;
        }
    }else if(location.y>ofGetHeight()-5*d){
        ofVec2f desired=ofVec2f(velocity.x,-maxSpeed);
        steer=desired-velocity;
        
        if(steer.length()>maxSpeed){
            steer.normalize();
            steer*=maxForce;
        }
    }
    
    addForce(steer);
}

