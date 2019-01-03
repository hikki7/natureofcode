//
//  Pendulim.hpp
//  Pendulum
//
//  Created by 引田祐樹 on 2018/12/07.
//

#pragma once
#ifndef Pendulim_hpp
#define Pendulim_hpp

#include <stdio.h>
#include "ofMain.h"

class Pendulim{
  
public:
    Pendulim(ofVec2f _origin,float _r);
    void update();
    void display();
    void clicked(float _mx,float _my);
    void stopDragging();
    void drag();
    
    ofVec2f location;
    ofVec2f origin;
    float r;
    float angle;
    float aVelocity;
    float aAcceleration;
    float rBall;
    float damping;
    bool dragging;
    
};

#endif /* Pendulim_hpp */
