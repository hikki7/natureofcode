//
//  vehicle.hpp
//  vehicle
//
//  Created by 引田祐樹 on 2018/12/14.
//

#pragma once
#ifndef vehicle_hpp
#define vehicle_hpp

#include <stdio.h>
#include "ofMain.h"

class vehicle {
    
public:
    
    vehicle();
    void update();
    void display();
    void addForce(ofVec2f _force);
    void seek(ofVec2f _target);
    
    
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float r;
    float maxForce;
    float maxSpeed;
    
};

#endif /* vehicle_hpp */
