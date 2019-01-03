//
//  Repeller.hpp
//  particleSystem01
//
//  Created by 引田祐樹 on 2018/12/11.
//

#pragma once
#ifndef Repeller_hpp
#define Repeller_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Particle.hpp"

class Repeller{
    
public:
    Repeller(ofVec2f _location);
    void display();
    ofVec2f repeller(Particle* p);
    
    float g;
    ofVec2f location;
    float r;
    
};

#endif /* Repeller_hpp */
