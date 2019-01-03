//
//  Particle.cpp
//  particleSystem01
//
//  Created by 引田祐樹 on 2018/12/10.
//

#include "Particle.hpp"

Particle::Particle(ofVec2f _location,float _hue){
    location=_location;
    velocity=ofVec2f(ofRandom(-1,1),0);
    acceleration=ofVec2f(0,0.05);
    lifeSpan=255;
    radius=20;
    angle=0;
    aVelocity=0;
    aAcceleration=0.001;
    hue=_hue;
    mass=1.0;
}

void Particle::update(){
    velocity+=acceleration;
    location+=velocity;
    lifeSpan-=1.0;
    acceleration*=0;
    aVelocity+=aAcceleration;
    angle+=aVelocity;
}


void Particle::addForce(ofVec2f _force){
    ofVec2f force=_force/mass;
    acceleration+=force;
}


virtual void Particle::display(){
    ofColor color;
    color.setHsb(hue, 255, 255);
    ofSetColor(color,lifeSpan);
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofRotateRad(angle);
    ofDrawCircle(0, 0, radius);
    ofPopMatrix();
}



bool Particle::dead(){
    if(lifeSpan<0){
        return true;
    }
    return false;
}


