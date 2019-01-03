//
//  Vehicle.hpp
//  FlowField
//
//  Created by 引田祐樹 on 2018/12/18.
//

#pragma once

#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <stdio.h>
#include "ofMain.h"

class Vehicle {
    
public:
    Vehicle();
    void update();
    void addForce(ofVec2f _force);
    void display();
    void follow(ofVec2f _desired);
    void border();
    
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float hue;
    float r;
    float maxSpeed;
    float maxForce;
    ofColor col;
};

#endif /* Vehicle_hpp */
