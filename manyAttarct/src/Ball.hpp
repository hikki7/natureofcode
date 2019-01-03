//
//  Ball.hpp
//  manyAttarct
//
//  Created by 引田祐樹 on 2018/12/02.
//

#pragma once
#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include "ofMain.h"

class Ball{
    
public:
    //--------------function
    Ball(float* _x,float* _y,float* _mass);
    void update();
    void display();
    void addForce(ofVec2f _force);
    void checkBound();
    ofVec2f attract(Ball* ball);
    
    
    //--------------variable
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float mass;
    float radius;
    float g;
    
};

#endif /* Ball_hpp */
