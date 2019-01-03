//
//  Ball.cpp
//  manyAttarct
//
//  Created by 引田祐樹 on 2018/12/02.
//

#include "Ball.hpp"

Ball::Ball(float* _x,float* _y,float* _mass){
    location=ofVec2f(*_x,*_y);
    velocity=ofVec2f(ofRandom(ofGetWidth(),ofGetWidth()),ofRandom(-ofGetHeight(),ofGetHeight()));
    velocity.normalize();
    velocity*=0.5;
    acceleration=ofVec2f(0,0);
    mass=*_mass;
    radius=mass*5;
    g=0.4;
}

void Ball::update(){
    velocity+=acceleration;
    location+=velocity;
    acceleration*=0;
}

void Ball::display(){
    ofSetColor(255);
    ofDrawCircle(location.x,location.y, radius);
}


void Ball::addForce(ofVec2f _force){
    ofVec2f force=_force/mass;
    acceleration+=force;
    
}

void Ball::checkBound(){
    
    float d=30;
    
    ofVec2f force=ofVec2f(0,0);
    
    if(location.x<d){
        force.x=1;
    }else if(location.x>ofGetWidth()-d){
        force.x=-1;
    }
    
    if(location.y<d){
        force.y=1;
    }else if (location.y>ofGetHeight()-d){
        force.y=-1;
    }
    
    addForce(force);
}

ofVec2f Ball::attract(Ball* ball){
    
    ofVec2f force=location-ball->location;
    float dist=ofDist(location.x, location.y, ball->location.x, ball->location.y);
    
    force.normalize();
    
    float strength=(g*mass*ball->mass)/(dist*dist);
    force*=strength;
    
    return force;
}
