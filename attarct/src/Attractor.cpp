//
//  Attractor.cpp
//  attarct
//
//  Created by 引田祐樹 on 2018/11/28.
//

#include "Attractor.hpp"

Attractor::Attractor(){
    location=ofVec2f(ofGetWidth()/2,ofGetHeight()/2);
    mass=20;
    G=1;
    dragOffset=ofVec2f(0,0);
    dragging=false;
    rollover=false;
    radius=mass;
}

ofVec2f Attractor::attract(Mover* m){
    ofVec2f force=location-m->location;
    float distance = force.length();
    if(distance<5){
        distance=5;
    }else if (distance>35){
        distance=35;
    }
    float forceMag=(G*mass*m->mass)/(distance*distance);
    force.normalize();
    force*=forceMag;
    return force;
}

void Attractor::display(){
    if(dragging){
        ofSetColor(125);
    }else if(rollover){
        ofSetColor(175);
    }else{
        ofSetColor(225);
    }
    ofDrawCircle(location.x, location.y, radius);
}

void Attractor::clicked(int mx, int my){
    float d=ofDist(mx, my, location.x, location.y);
    if(d<radius){
        dragging=true;
        dragOffset.x=location.x-mx;
        dragOffset.y=location.y-my;
    }
}

void Attractor::hover(int mx, int my){
    float d=ofDist(mx, my, location.x, location.y);
    if(d<radius){
        rollover=true;
    }else{
        rollover=false;
    }
}

void Attractor::stopDragging(){
    dragging=false;
}

void Attractor::drag(){
    //cout<<dragging<<endl;

    if(dragging){
        location=ofVec2f(ofGetMouseX()+dragOffset.x,ofGetMouseY()+dragOffset.y);
    }
}
