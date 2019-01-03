//
//  vehicle.hpp
//  vehicleBound
//
//  Created by 引田祐樹 on 2018/12/16.
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
    void bounding();    
    
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float r;
    float maxForce;
    float maxSpeed;
    float d;
    
};

#endif /* vehicle_hpp */
