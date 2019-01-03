//
//  Attractor.hpp
//  attarct
//
//  Created by 引田祐樹 on 2018/11/28.
//

#pragma once
#ifndef Attractor_hpp
#define Attractor_hpp

#include <stdio.h>
#include "Mover.hpp"

class Attractor {
    
    
public:
    Attractor();
    ofVec2f attract(Mover* m);
    
    void display();
    void clicked(int mx,int my);
    void hover(int mx,int my);
    void stopDragging();
    void drag();
    
    
    float mass;
    float G;
    ofVec2f location;
    bool dragging;
    bool rollover;
    ofVec2f dragOffset;
    float radius;
    
    
};

#endif /* Attractor_hpp */
