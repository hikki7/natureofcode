//
//  particle.hpp
//  particleSystem02
//
//  Created by 引田祐樹 on 2018/12/11.
//

#pragma once
#ifndef particle_hpp
#define particle_hpp

#include <stdio.h>
#include "ofMain.h"

class particle{
  
public:
    particle(float* mass);
    void addForce(ofVec2f* _force);
    void update();
    void display();
    bool dead();
    
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float lifeSpan;
    float angle;
    float aAcceleration;
    float mass;
    float hue;
};

#endif /* particle_hpp */
