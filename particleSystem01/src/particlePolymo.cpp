//
//  particlePolymo.cpp
//  particleSystem01
//
//  Created by 引田祐樹 on 2018/12/10.
//

#include "particlePolymo.hpp"

particlePolymo::particlePolymo(ofVec2f _location,float _hue){
    Particle::Particle(ofVec2f _location,float _hue);
}

void particlePolymo::update(){
    Particle::update();
}

void particlePolymo::addForce(ofVec2f _force){
    Particle::addForce(ofVec2f _force);
}


void particlePolymo::display(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofColor color;
    color.setHsb(hue, 255, 255);
    ofSetColor(color,lifeSpan);
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofRotateRad(angle);
    ofDrawRectangle(0, 0, radius,radius);
    ofPopMatrix();
}

bool particlePolymo::dead(){
    Particle::dead();
}
