//
//  particleSystem.cpp
//  particleSystem02
//
//  Created by 引田祐樹 on 2018/12/11.
//

#include "particleSystem.hpp"

particleSystem::particleSystem(){
    
}
void particleSystem::addParticle(){
    float _hue=ofRandom(0.1,2.0);
    ps.push_back(new particle(&_hue));
}

void particleSystem::addForce(ofVec2f* _force){
    
    ofVec2f force=*_force;
    for (int i=ps.size()-1; i>=0; i--) {
        particle* p=ps[i];
        p->addForce(& force);
    }
}

void particleSystem::control(){
    for (int i=ps.size()-1; i>=0; i--) {
        particle* p=ps[i];
        p->update();
        if(p->dead()){
            ps[i]=ps.back();
            ps.pop_back();
        }
    }
}

void particleSystem::particleDisplay(){
    for (int i=ps.size()-1; i>=0; i--) {
        particle* p=ps[i];
        p->display();
    }
}

void particleSystem::applyRepeller(repeller* rp){
    for(int i=ps.size()-1;i>=0;i--){
        particle* p=ps[i];
        ofVec2f force=*rp->repellerVec(&p);
        p->addForce(&force);
    }
}
