
//
//  vehicle.cpp
//  separation
//
//  Created by 引田祐樹 on 2018/12/30.
//

#include "vehicle.hpp"

using namespace glm;

vehicle::vehicle(glm::vec2 l,float ms,float mf){
    location=l;
    maxSpeed=ms;
    maxForce=mf;
    acceleration=vec2(0,0);
    velocity=vec2(maxSpeed,0);
    r=30;
}

vehicle::~vehicle(){
    
}

void vehicle::follow(Path &p){
    
    //-----------------行く方向の予測
    vec2 predict=velocity;
    predict=normalize(predict);
    predict*=50;
    vec2 predictloc=location+predict;
    
    //-----------------経路を求める
    auto *path=&p;
    vec2 a=path->start;
    vec2 b=path->end;
    vec2 normalPoint=getNormalPoint(predictloc, a, b);
    
    //-----------------目標設定
    vec2 dir=b-a;
    dir=normalize(dir);
    dir*=10;
    vec2 target=dir+normalPoint;
    
    //----------------経路から外れた場合、戻る
    float distance=length(predictloc-normalPoint);
    if(distance>path->radius){
        seek(target);
    }
    
}

vec2 vehicle::getNormalPoint(vec2 p, vec2 a, vec2 b){
    vec2 ap=p-a;
    vec2 ab=b-a;
    ab=normalize(ab);
    ab*=dot(ap, ab);
    vec2 normalPoint=a+ab;
    return normalPoint;
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

void vehicle::addForce(vec2 _force){
    acceleration+=_force;
}

void vehicle::seek(vec2 target){
    vec2 desired=target-location;
    if(length(desired)==0){
        return;
    }
    desired=normalize(desired);
    desired*=maxSpeed;
    
    vec2 steer=desired-velocity;
    if(length(steer)>maxForce){
        steer=normalize(steer);
        steer*=maxForce;
    }
    
    addForce(steer);
}

void vehicle::display(){
    float theta=atan2(velocity.y, velocity.x)+PI/2;
    ofSetColor(255,0,0);
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofRotateRad(theta);
    ofDrawTriangle(0, -r*sin(PI/3),-r*cos(PI/3),r*sin(PI/3),r*cos(PI/3),r*sin(PI/3));
    ofPopMatrix();
}

void vehicle::border(Path &p){
    auto *path=&p;
    if(location.x>path->end.x+r){
        location.x=path->start.x-r;
        location.y=path->start.y+(location.y-path->end.y);
    }
}
