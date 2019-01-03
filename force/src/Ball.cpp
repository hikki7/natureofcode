
//
//  Ball.cpp
//  force
//
//  Created by 引田祐樹 on 2018/11/25.
//

#include "Ball.hpp"

Ball::Ball(float _mass){
    mass=_mass;
    radius=mass*3;
    speed=5;
    location=ofVec2f(0,0);
    velocity=ofVec2f(0,0);
    acceleration=ofVec2f(0,0);
    velocity.normalize();
    velocity*=speed;
}

void Ball::update(){
    velocity+=acceleration;
    location+=velocity;
    acceleration=ofVec2f(0,0);

    if(location.x>ofGetWidth()||location.x<0){
        velocity.x*=-1;
    }
    if(location.y>ofGetHeight()||location.y<0){
        velocity.y*=-1;
    }
}

void Ball::display(){
    ofSetColor(255);
    ofDrawCircle(location.x, location.y, radius);
}

void Ball::addForce(ofVec2f _force){
    force=_force/mass;
    acceleration+=force;
}
