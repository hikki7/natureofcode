//
//  vehicle.hpp
//  separation2
//
//  Created by 引田祐樹 on 2019/01/04.
//

#pragma once
#ifndef vehicle_hpp
#define vehicle_hpp

#include <stdio.h>
#include "ofMain.h"

using namespace glm;

class vehicle{
  
public:
    vehicle(float x,float y);
    ~vehicle();
    void addForce(vec2 _force);
    void separate(vector<unique_ptr<vehicle>>& vehicles);
    void update();
    void display();
    void borders();
    
    vec2 location;
    float r;
    
private:
    vec2 acceleration;
    vec2 velocity;
    float maxSpeed;
    float maxForce;
    
};

#endif /* vehicle_hpp */
