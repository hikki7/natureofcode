//
//  Mover.cpp
//  attarctIntaractive
//
//  Created by 引田祐樹 on 2018/11/28.
//

#include "Mover.hpp"

Mover::Mover(float _mass,ofVec2f pos){
    mass=_mass;
    location=pos;
    radius=mass*5;
    velocity=ofVec2f(0,0);
    acceleration=ofVec2f(0,0);
    G=0.4;
    
}

void Mover::update(){
    velocity+=acceleration;
    location+=velocity;
    acceleration*=0;
    
}

void Mover::display(){
    ofSetColor(255);
    ofDrawCircle(location, radius);
}

void Mover::addForce(ofVec2f _force){
    ofVec2f force=_force/mass;
    acceleration+=force;
}

ofVec2f Mover::attract(Mover* m){
    ofVec2f force=location-m->location;
    float distance = ofDist(location.x, location.y, m->location.x, m->location.y);
    float forceMag=(G*mass*m->mass)/(distance*distance);
    force.normalize();
    force*=forceMag;
    return force;
}
