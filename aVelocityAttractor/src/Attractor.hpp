//
//  Attractor.hpp
//  aVelocityAttractor
//
//  Created by 引田祐樹 on 2018/12/05.
//

#pragma once
#ifndef Attractor_hpp
#define Attractor_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Mover.hpp"

class Attractor{
    
public:
    
    Attractor();
    ofVec2f attract(Mover* m);
    void display();
    
    float mass;
    ofVec2f location;
    float g;
    
};

#endif /* Attractor_hpp */
