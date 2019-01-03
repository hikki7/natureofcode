//
//  Mover.hpp
//  attarct
//
//  Created by 引田祐樹 on 2018/11/28.
//
#pragma once
#ifndef Mover_hpp
#define Mover_hpp

#include <stdio.h>
#include "ofMain.h"

class Mover{
    
public:
    Mover(float mass,ofVec2f _pos);
    void update();
    void display();
    void addForce(ofVec2f _force);
    
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    ofVec2f force;
    float speed;
    int radius;
    float mass;
    
};
#endif /* Mover_hpp */
