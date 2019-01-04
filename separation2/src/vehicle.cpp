
//
//  vehicle.cpp
//  separation2
//
//  Created by 引田祐樹 on 2019/01/04.
//

#include "vehicle.hpp"

using namespace glm;

vehicle::vehicle(float x,float y){
    location=vec2(x,y);
    maxSpeed=3;
    maxForce=0.2;
    acceleration=vec2(0,0);
    velocity=vec2(0,0);
    r=10;
}

vehicle::~vehicle(){
    
}

void vehicle::addForce(vec2 _force){
    acceleration+=_force;
}

void vehicle::applyBehaviors(vector<unique_ptr<vehicle>>& vehicles){
    vec2 separateForce=separate(vehicles);
    vec2 seekForce=seek(vec2(ofGetMouseX(),ofGetMouseY()));
    separateForce*=5;
    addForce(separateForce);
    addForce(seekForce);
}


vec2 vehicle::seek(vec2 target){
    vec2 desired=target-location;
    desired=normalize(desired);
    desired*=maxSpeed;;
    
    vec2 steer=desired-velocity;
    if(length(steer)>maxForce){
        steer=normalize(steer);
        steer*=maxForce;
    }
    
    return steer;
}

vec2 vehicle::separate(vector<unique_ptr<vehicle>>& vehicles){
    float desiredseparation=2*r;//近すぎないかの基準
    vec2 sum=vec2(0,0);
    int count=0;
    
    for(auto& other:vehicles){
        float d=length(this->location-other->location);
        if(d>0&&d<desiredseparation){
            vec2 diff=this->location-other->location;
            diff=normalize(diff);
            diff/=d;
            sum+=diff;
            count++;
        }
    }
    return sum;
}

void vehicle::update(){
    velocity+=acceleration;
    if(length(velocity)>maxSpeed){
        velocity=normalize(velocity);
        velocity*=maxSpeed;
    }
    location+=velocity;
    acceleration*=0;
}

void vehicle::display(){
    ofSetColor(127);
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofDrawCircle(0, 0, r);
    ofPopMatrix();
}

void vehicle::borders(){
    
    if(location.x<-r){
        location.x=ofGetWidth()+r;
    }else if (location.x>ofGetWidth()+r){
        location.x=-r;
    }
    
    if(location.y<-r){
        location.y=ofGetHeight()+r;
    }else if(location.y>ofGetHeight()+r){
        location.y=-r;
    }
}
