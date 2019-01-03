//
//  FlowField.cpp
//  FlowField
//
//  Created by 引田祐樹 on 2018/12/17.
//

#include "FlowField.hpp"


FlowField::FlowField(){
    init();
}

void FlowField::init(){
    float zoff=ofRandom(10000);
    field.resize(cols);
    for(int i=0;i<cols;i++){
        field[i].resize(rows);
        for(int j=0;j<rows;j++){
            float theta=ofMap(ofNoise(i*0.1,j*0.1,zoff),0,1,0,PI*2);
            field[i][j]=ofVec2f(cos(theta),sin(theta));
        }
    }
    
}

void FlowField::display(){
    for(int i=0;i<cols;i++){
        for(int j=0;j<rows;j++){
            drawVector(field[i][j],i*resolution,j*resolution,resolution-2);
        }
    }
}

void FlowField::drawVector(ofVec2f _theta,float x,float y,float scale){
    ofPushMatrix();
    ofTranslate(x,y);
    ofRotateRad(atan2(_theta.y,_theta.x));
    ofSetColor(255);
    ofDrawLine(0,0,scale,0);
    ofPopMatrix();
}

ofVec2f FlowField::lookup(ofVec2f _lookup){
    int column=int(_lookup.x/resolution);
    if(column<0){
        column=0;
    }else if(column>cols-1){
        column=cols-1;
    }
    
    int row=int(_lookup.y/resolution);
    if(row<0){
        row=0;
    }else if(row>rows-1){
        row=rows-1;
    }
    
    return field[column][row];
}
