//
//  Particle.hpp
//  particleSystem01
//
//  Created by 引田祐樹 on 2018/12/10.
//

#pragma once
#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include "ofMain.h"
class Particle{
    
public:
    Particle(ofVec2f _location,float _hue);
    void update();
    void addForce(ofVec2f _force);
    void display();
    bool dead();
    
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float lifeSpan;
    float radius;
    float aAcceleration;
    float aVelocity;
    float angle;
    float hue;
    float mass;
};

#endif /* Particle_hpp */
