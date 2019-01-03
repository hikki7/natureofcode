//
//  ParticleVec2.cpp
//  force1
//
//  Created by 引田祐樹 on 2018/11/25.
//

#include "ParticleVec2.hpp"
//#include "ParticleVec2.h"

ParticleVec2::ParticleVec2(){
    friction = 0.01;
    radius = 5.0;
    position = glm::vec2(ofGetWidth()/2.0, ofGetHeight()/2.0);
    velocity = glm::vec2(0, 0);
}

void ParticleVec2::update(){
    acceleration -= velocity * friction;
    velocity += acceleration;
    position += velocity;
    acceleration = glm::vec2(0, 0);
}

void ParticleVec2::draw(){
    ofDrawCircle(position.x, position.y, radius);
}

void ParticleVec2::bounceOfWalls(){
    if (position.x < 0 || position.x > ofGetWidth()) {
        velocity.x *= -1;
    }
    if (position.y < 0 || position.y > ofGetHeight()) {
        velocity.y *= -1;
    }
}
