//
//  particleSystem.hpp
//  particleSystem02
//
//  Created by 引田祐樹 on 2018/12/11.
//

#pragma once
#ifndef particleSystem_hpp
#define particleSystem_hpp

#include <stdio.h>
#include "ofMain.h"
#include "particle.hpp"
#include "repeller.hpp"

class particleSystem {
    
public:
    particleSystem();
    void addParticle();
    void addForce(ofVec2f* _force);
    void control();
    void particleDisplay();
    void applyRepeller(repeller* rp);
    
    vector<particle*> ps;
    repeller* rp;
    
};

#endif /* particleSystem_hpp */
