//
//  Mover.hpp
//  attarctIntaractive
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
    Mover(float _mass,ofVec2f pos);
    void update();
    void display();
    void addForce(ofVec2f _force);
    ofVec2f attract(Mover* m);
    
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float G;
    float mass;
    float radius;
};

#endif /* Mover_hpp */
