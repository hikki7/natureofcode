//
//  Mover.hpp
//  aVelocityAttractor
//
//  Created by 引田祐樹 on 2018/12/05.
//
#pragma once
#ifndef Mover_hpp
#define Mover_hpp

#include <stdio.h>
#include "ofMain.h"

class Mover{
    
public:
    Mover(float _m,float _x,float _y);
    void addForce(ofVec2f _force);
    void update();
    void display();
    
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float m;
    
    float aAcceleration;
    float aVelocity;
    float angle;
    
};


#endif /* Mover_hpp */
