//
//  Boid.cpp
//  Flock
//
//  Created by 引田祐樹 on 2019/01/04.
//

#include "Boid.hpp"

using namespace glm;

Boid::Boid(float x,float y){
    location=vec2(x,y);
    maxSpeed=3;
    maxForce=0.2;
    acceleration=vec2(0,0);
    velocity=vec2(ofRandom(-3,3),ofRandom(-3,3));
    r=10;
    range=40;
    col.setHsb(ofRandom(255),255,255);
}

Boid::~Boid(){
    
}

void Boid::addForce(vec2 _force){
    acceleration+=_force;
}

void Boid::flock(vector<unique_ptr<Boid>>& boids){
    vec2 sep=separate(boids);
    vec2 ali=align(boids);
    vec2 coh=cohesion(boids);
    
    //いい感じで調節する
    sep*=1.5;
    ali*=1.0;
    coh*=1.0;
    
    addForce(sep);
    addForce(ali);
    addForce(coh);
}

void Boid::update(){
    velocity+=acceleration;
    if(length(velocity)>maxSpeed){
        velocity=normalize(velocity);
        velocity*=maxSpeed;
    }
    location+=velocity;
    acceleration*=0;
}

vec2 Boid::seek(vec2 target){
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

void Boid::display(){
    float theta=atan2(velocity.y, velocity.x)+PI/2;
    ofSetColor(col);
    ofPushMatrix();
    ofTranslate(location.x, location.y);
    ofRotateRad(theta);
    ofDrawTriangle(0, -r*sin(PI/3),-r*cos(PI/3),r*sin(PI/3),r*cos(PI/3),r*sin(PI/3));
    ofPopMatrix();
}

void Boid::borders(){
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

//周りとの激突を防ぐため
vec2 Boid::separate(vector<unique_ptr<Boid>>& boids){
    float desiredseparation=2*r;//近すぎないかの基準
    vec2 sum=vec2(0,0);
    int count=0;
    
    for(auto& other:boids){
        float d=length(this->location-other->location);
        if(d>0&&d<desiredseparation){
            vec2 diff=this->location-other->location;
            diff=normalize(diff);
            diff/=d;
            sum+=diff;
            count++;
        }
    }
    
    if(length(sum)>0){
        sum/=count;
    }
    
    if(length(sum)>0){
        sum=normalize(sum);
        sum*=maxSpeed;
        sum-=velocity;
        if(length(sum)>maxForce){
            sum=normalize(sum);
            sum*=maxForce;
        }
    }
    return sum;
}


//周りと同じ方向に飛ばすため
vec2 Boid::align(vector<unique_ptr<Boid>>& boids){
    vec2 sum=vec2(0,0);
    int count=0;
    
    for(auto& other:boids){
        float d=length(this->location-other->location);
        if(d>0 && d<range){
            sum+=other->velocity;
            count++;
        }
    }
    
    if(count>0){
        sum/=count;
        sum=normalize(sum);
        sum*=maxSpeed;
        vec2 steer=sum-velocity;
        if(length(steer)>maxForce){
            steer=normalize(steer);
            steer*=maxForce;
        }
        return steer;
    }else{
        return vec2(0,0);
    }
}

//できるだけ集団の中心に行くようにする
vec2 Boid::cohesion(vector<unique_ptr<Boid>>& boids){
    vec2 sum=vec2(0,0);
    int count=0;
    for(auto& other:boids){
        float d=length(this->location-other->location);
        if(d>0 && d<range){
            sum+=other->location;
            count++;
        }
    }
    
    if(count>0){
        sum/=count;
        return seek(sum);
    }else{
        return vec2(0,0);
    }
}
