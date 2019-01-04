//
//  vehicle.hpp
//  separation
//
//  Created by 引田祐樹 on 2018/12/30.
//

#pragma once
#ifndef vehicle_hpp
#define vehicle_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Path.hpp"

class vehicle{
  
public:
    vehicle(glm::vec2 l,float ms,float mf);
    ~vehicle();
    void follow(Path &p);
    glm::vec2 getNormalPoint(glm::vec2 p, glm::vec2 a, glm::vec2 b);
    void update();
    void addForce(glm::vec2 _force);
    void seek(glm::vec2 target);
    void display();
    void border(Path &p);
    
private:
    glm::vec2 location;
    glm::vec2 velocity;
    glm::vec2 acceleration;
    float r;
    float maxForce;
    float maxSpeed;
    
};

#endif /* vehicle_hpp */
