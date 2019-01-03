//
//  Mover.hpp
//  pointting_velocity
//
//  Created by 引田祐樹 on 2018/12/06.
//

#pragma once;
#ifndef Mover_hpp
#define Mover_hpp

#include <stdio.h>
#include "ofMain.h"

class Mover {
    
public:
    Mover();
    void update();
    void display();
    void checkEdge();
    
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    float topSpeed;
    float r;
};

#endif /* Mover_hpp */
