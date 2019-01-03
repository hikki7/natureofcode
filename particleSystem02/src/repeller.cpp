//
//  repeller.cpp
//  particleSystem02
//
//  Created by 引田祐樹 on 2018/12/12.
//

#include "repeller.hpp"

repeller::repeller(){
    location=ofVec2f(ofGetWidth()/2,ofGetHeight()/2);
    float mass=30;
    float G=50;
    float r=50;
}

void repeller::display(){
    ofSetColor(255,0,0);
    ofDrawCircle(location.x, location.y, r);
}

ofVec2f repeller::repellerVec(particle* p){
    ofVec2f force;
    
    force=p->location-location;
    float dist=force.length();
    if(dist<20){
        dist=20;
    }
    force.normalize();
    float mag=(G*p->mass*mass)/(dist*dist);
    force*=mag;
    return force;
}
