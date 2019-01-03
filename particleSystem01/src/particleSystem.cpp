//
//  particleSystem.cpp
//  particleSystem01
//
//  Created by 引田祐樹 on 2018/12/10.
//

#include "particleSystem.hpp"

particleSystem::particleSystem(ofVec2f _location){
    location=_location;
}

void particleSystem::createParticle(){
    particles.push_back(new Particle(location,ofRandom(255)));
}

void particleSystem::control(){
    for(int i=particles.size()-1;i>=0;i--){
        Particle* p=particles[i];
        p->update();
        if(p->dead()){
            particles[i]=particles.back();
            particles.pop_back();
        }
    }
}

void particleSystem::drawParticle(){
    for(int i=particles.size()-1;i>=0;i--){
        Particle* p=particles[i];
        p->display();
    }
}

void particleSystem::addForce(ofVec2f _force){
    ofVec2f force=_force;
    for(int i=particles.size()-1;i>=0;i--){
        Particle* p=particles[i];
        p->addForce(force);
    }
}




