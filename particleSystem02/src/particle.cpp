//
//  particle.cpp
//  particleSystem02
//
//  Created by 引田祐樹 on 2018/12/11.
//

#include "particle.hpp"

particle::particle(float* _mass){
    location=ofVec2f(ofGetWidth()/2,0);
    velocity=ofVec2f(ofRandom(-2,2),1);
    acceleration=ofVec2f(0,0);
    lifeSpan=255;
    angle=0;
    aAcceleration=0.01;
    mass=*_mass;
    hue=ofRandom(255);
}

void particle::addForce(ofVec2f* _force){
    ofVec2f force=*_force;
    force/=mass;
    acceleration+=force;
}

void particle::update(){
    velocity+=acceleration;
    location+=velocity;
    acceleration*=0;
    
    angle+=aAcceleration;
    lifeSpan-=1;
}

void particle::display(){
    float r=mass;
    r*=20;
    
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofRotateRad(angle);
    ofColor color;
    color.setHsb(hue,255,255);
    ofSetColor(color,lifeSpan);
    ofDrawCircle(0, 0, r);
    ofPopMatrix();
}

bool particle::dead(){
    if (lifeSpan<0) {
        return true;
    }
    return false;
}
