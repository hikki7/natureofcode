//
//  Ball.hpp
//  force
//
//  Created by 引田祐樹 on 2018/11/25.
//

#ifndef Ball_hpp
#define Ball_hpp

#pragma once
#include <stdio.h>
#include "ofMain.h"

class Ball{
    
public:
    Ball(float _mass);
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

#endif /* Ball_hpp */
