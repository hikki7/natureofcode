//
//  Attractor.cpp
//  aVelocityAttractor
//
//  Created by 引田祐樹 on 2018/12/05.
//

#include "Attractor.hpp"


Attractor::Attractor(){
    location=ofVec2f(ofGetWidth()/2,ofGetHeight()/2);
    mass=20;
    g=0.4;
}

ofVec2f Attractor::attract(Mover* m){
    ofVec2f force=location - m->location;
    float dist =force.length();
    
    if(dist>40){
        dist=40;
    }else if(dist<5){
        dist=5;
    }
    
    force.normalize();
    float forceMag=(g*mass*m->m)/(dist*dist);
    
    force*=forceMag;
    return force;
}

void Attractor::display(){
    ofSetColor(144);
    ofDrawCircle(location.x, location.y, mass*2);
}
