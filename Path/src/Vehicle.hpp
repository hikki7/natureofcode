#pragma once
#ifndef Vehicle_hpp
#define Vehicle_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Path.hpp"

class Vehicle{
    
public:
    Vehicle(glm::vec2 l,float ms,float mf);
    Vehicle();
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

#endif /* Vehicle_hpp */
