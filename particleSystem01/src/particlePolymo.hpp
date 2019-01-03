//
//  particlePolymo.hpp
//  particleSystem01
//
//  Created by 引田祐樹 on 2018/12/10.
//

#pragma once
#ifndef particlePolymo_hpp
#define particlePolymo_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Particle.hpp"

class particlePolymo :public Particle{
    
public:
    
    particlePolymo(ofVec2f _location,float _hue);
    void update();
    void addForce(ofVec2f _force);
    void display();
    bool dead();

    
    
};

#endif /* particlePolymo_hpp */
