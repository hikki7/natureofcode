#pragma once
#include "ofMain.h"

class ParticleVec2 {
    
public:
    ParticleVec2();
    void update();
    void draw();
    void bounceOfWalls();
    
    glm::vec2 position;
    glm::vec2 velocity;
    glm::vec2 acceleration;
    float radius;
    float friction;
};
