//
//  Path.hpp
//  separation
//
//  Created by 引田祐樹 on 2018/12/30.
//

#pragma once
#ifndef Path_hpp
#define Path_hpp

#include <stdio.h>
#include "ofMain.h"

class Path{
    
public:
    Path();
    ~Path();
    void display();
    
    glm::vec2 start;
    glm::vec2 end;
    
    float radius;
    
private:
    
    
};

#endif /* Path_hpp */
