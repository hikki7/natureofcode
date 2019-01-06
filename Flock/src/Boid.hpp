//
//  Boid.hpp
//  Flock
//
//  Created by 引田祐樹 on 2019/01/04.
//

#pragma once
#ifndef Boid_hpp
#define Boid_hpp

#include <stdio.h>
#include "ofMain.h"

using namespace glm;

class Boid {
    
public:
    Boid(float x,float y);
    ~Boid();
    void addForce(vec2 force);
    void flock(vector<unique_ptr<Boid>>& boids);
    void update();
    vec2 seek(vec2 target);
    void display();
    void borders();
    vec2 separate(vector<unique_ptr<Boid>>& boids);
    vec2 align(vector<unique_ptr<Boid>>& boids);
    vec2 cohesion(vector<unique_ptr<Boid>>& boids);
    
    vec2 location;
    vec2 velocity;
    
private:
    vec2 acceleration;
    float maxSpeed;
    float maxForce;
    float r;
    float range;
    ofColor col;
};

#endif /* Boid_hpp */
