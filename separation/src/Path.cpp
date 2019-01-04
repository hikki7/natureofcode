
//
//  Path.cpp
//  separation
//
//  Created by 引田祐樹 on 2018/12/30.
//

#include "Path.hpp"

using namespace glm;


Path::Path(){
    radius=20;
    start=vec2(0,ofGetHeight()/3);
    end=vec2(ofGetWidth(),ofGetHeight()*2/3);
    
}

Path::~Path(){
    
    
    
}

void Path::display(){
    float angle=atan2(end.y-start.y, end.x-start.x);
    float width=distance(start, end);
    ofPushMatrix();
    ofTranslate(start.x, start.y);
    ofRotateRad(angle);
    ofSetColor(255);
    ofDrawRectangle(0, 0, width, radius);
    ofPopMatrix();
}
