//
//  repeller.hpp
//  particleSystem02
//
//  Created by 引田祐樹 on 2018/12/12.
//

#pragma once
#ifndef repeller_hpp
#define repeller_hpp

#include <stdio.h>
#include "ofMain.h"
#include "particle.hpp"

class repeller{
  
public:
    repeller();
    void display();
    ofVec2f repellerVec(particle* p);
    
    ofVec2f location;
    float mass;
    float G;
    float r;
    
};

#endif /* repeller_hpp */
