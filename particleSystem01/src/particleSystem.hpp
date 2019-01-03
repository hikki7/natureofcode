//
//  particleSystem.hpp
//  particleSystem01
//
//  Created by 引田祐樹 on 2018/12/10.
//

#pragma once
#ifndef particleSystem_hpp
#define particleSystem_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Particle.hpp"

class particleSystem{
    
public:
    
    particleSystem(ofVec2f _location);
    void createParticle();
    void control();
    void drawParticle();
    void addForce(ofVec2f _force);
    
    
    vector<Particle*> particles;
    ofVec2f location;
    
};

#endif /* particleSystem_hpp */
