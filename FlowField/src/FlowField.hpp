//
//  FlowField.hpp
//  FlowField
//
//  Created by 引田祐樹 on 2018/12/17.
//

#pragma once
#ifndef FlowField_hpp
#define FlowField_hpp

#include <stdio.h>
#include "ofMain.h"


class FlowField {
    
public:
    
    static const int resolution=25;
    const int cols=(int)(ofGetWidth()/resolution);
    const int rows=(int)(ofGetHeight()/resolution);
    
    FlowField();
    void init();
    void display();
    void drawVector(ofVec2f _theta,float x,float y,float scal);
    ofVec2f lookup(ofVec2f _lookup);
    
    vector<vector<ofVec2f>> field;

};


#endif /* FlowField_hpp */
